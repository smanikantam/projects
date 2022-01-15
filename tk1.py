from tkinter import *
counth=0
countv=0
root=Tk()
#labels
L=Label(root,text="enter here")
#entry
E=Entry(root)
E1=Text(root)

#function
def B():
	global e,countv,counth
	counth=0
	countv=0
	E1.delete("1.0","end")
	e=E.get()
	E1.insert(END,e)
def Bu():
	global counth,countv
	if countv>0:
		countv-=1
		E1.delete("1.0","end")
		a="\n"*countv
		x=a+" "*counth
		y=str(x)+str(e)
		E1.insert(END,y)
	print(counth,countv)

def Bl():
	global counth,countv
	if countv>=0 and counth>0:
		counth-=1
		E1.delete("1.0","end")
		a="\n"*countv
		x=" "*counth
		y=str(a)+str(x)+str(e)
		E1.insert(END,y)

	print(counth,countv)

def Br():
	global counth,countv
	if countv>=0 and counth>=0:
		counth+=1
		E1.delete("1.0","end")
		a="\n"*countv
		x=" "*counth
		y=str(a)+str(x)+str(e)
		E1.insert(END,y)

	print(counth,countv)

def Bd():
	global counth,countv
	if countv>=0:
		countv+=1
		E1.delete("1.0","end")
		a="\n"*countv
		x=a+" "*counth
		y=str(x)+str(e)
		E1.insert(END,y)
	print(counth,countv)

#buttons
B=Button(root,text="enter",command=B)
BL=Button(root,text="<",command=Bl)
BR=Button(root,text=">",command=Br)
BU=Button(root,text="^",command=Bu)
BD=Button(root,text="v",command=Bd)
#grid

E1.grid(row=10,column=2,ipadx=30,ipady=50)
L.grid(row=15,column=2)
E.grid(row=16,column=2)
B.grid(row=17,column=2)
BU.grid(row=16,column=4)
BL.grid(row=17,column=3)
BR.grid(row=17,column=5)
BD.grid(row=18,column=4)


root.mainloop()
