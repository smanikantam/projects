from sklearn.datasets import fetch_openml
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from tkinter import *
from PIL import Image,ImageGrab,ImageFilter

mnist=fetch_openml('MNIST_784')
x,y=mnist['data'],mnist['target']
x=np.array(x)
some_digit = x[36001]
some_digit_image=some_digit.reshape(28, 28)

x_train,x_test=x[:60000],x[60000:]
y_train,y_test=y[:60000],y[60000:]

y_train=y_train.astype(np.int8)
y_test=y_test.astype(np.int8)
y_train_2=(y_train==2)
y_test_2=(y_test==2)

clf=LogisticRegression(tol=0.1)

print(clf.fit(x_train,y_train_2))
print(clf.predict([some_digit]))


shuffle_index=np.random.permutation(60000)
x_train,y_trian=x_train[shuffle_index],y_train[shuffle_index]

a=cross_val_score(clf,x_train,y_train_2,cv=3,scoring="accuracy")

print(a.mean())

root = Tk()

def getx_y(event):
    global lapx,lapy
    lapx,lapy=event.x,event.y
def mov(event):
    global lapx,lapy
    can.create_line((lapx,lapy,event.x,event.y),fill='white',width=6)
    lapx,lapy=event.x,event.y
def clear():
    can.delete('all')
def B():
    global x_train,y_train,shuffle_index,y_train_2,clf,some_digit
    print(type(can))
    img=ImageGrab.grab(bbox=(256,226,760,730))
    img.save("px.png","png")
    img=img.resize((28,28))
    img=img.convert("L")
    #img=img.convert("1")
    img=np.array(img)
    img=img.reshape(1,-1,28,28)
    #print(clf.fit(img,y_train_2))
    img=img.flatten()
    print(clf.predict([img]))
    #shuffle_index=np.random.permutation(60000)
    #x_train,y_trian=x_train[shuffle_index],y_train[shuffle_index]

    #a=cross_val_score(clf,img,some_digit,cv=3,scoring="accuracy")

    #print("new",a.mean())
    
root.geometry("400x450+200+150")

can=Canvas(root,bg="black",width=400,height=400)
can.pack()

can.bind("<Button-1>",getx_y)
can.bind("<B1-Motion>",mov)

B=Button(root,text="enter",command=B)
B_clear=Button(root,text="clear",command=clear)
B_clear.pack()
B.pack()

root.mainloop()
