from tkinter import *
from math import *
root=Tk()

root.geometry("500x350")

root.title('math expression')

#text
#entvar=Entry(root)
entexp=Entry(root)
entx=Entry(root)
enty=Entry(root)
entans=Entry(root)

#functions

def buttans():


	entans.delete("0","end")#delete("starting index","last index")
	x=int(entx.get())
	y=int(enty.get())
	exp=entexp.get()
	exp.replace('x',str(x))
	exp.replace('y',str(y))
	entans.insert(0,eval(exp))
	return exp

#labels

#labvar=Label(root,text='how many variables')
labexp=Label(root,text='give expression')
labx=Label(root,text='x')
laby=Label(root,text='y')
labans=Label(root,text='exp ans')


#buttons
butt_ans=Button(root,text='enter',command=buttans)

#labvar.grid(row=0,column=0)
#entvar.grid(row=1,column=0)
labexp.grid(row=3,column=0)
entexp.grid(row=4,column=0)
#buttexp.grid(row=4,column=1)
labx.grid(row=5,column=0)
laby.grid(row=5,column=1)
labans.grid(row=5,column=2)
entx.grid(row=6,column=0)
enty.grid(row=6,column=1)
entans.grid(row=6,column=2)
butt_ans.grid(row=7,column=2,columnspan=2)

root.mainloop()
