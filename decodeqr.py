from pyzbar.pyzbar import decode
import qrcode as qr
from tkinter import *
from PIL import ImageTk,Image
import easygui
import os
import sys
root=Tk()
root.title("decode qrcode")
root.geometry("1000x800")

def makeqr2(root):
	global c
	c=0
	c+=1
	global data,entryqr
	data=entryqr.get("1.0","end")
	print(data)
	dataqr=qr.make(data)
	a="dataqrcode"+str(c)+".png"
	dataqr.save(a)
	frame=Frame(root)
	frame.pack()
	frame.place()
	
	img = ImageTk.PhotoImage(Image.open(a))
	label = Label(frame, image = img)
	label.image=img
	label.pack()

def makeqr(root,d=""):
	global data,entryqr
	data=d
	label=Label(root,text="enter here to make qrcode")
	label.pack()
	entryqr=Text(root)
	entryqr.pack()
	entryqr.insert(END,data)
	button=Button(root,text="submit",command=lambda:makeqr2(root))
	button.pack()

def editqr():
	global decodeqrdata
	edit=Toplevel() #because two simultinous Tk() will not run so we use Toplevel
	decodeqr(edit)
	makeqr(edit,decodeqrdata)
	edit.mainloop()
def decodeqr(root):
	global data,decodeqrdata
	imgpath=easygui.fileopenbox()
	decodeqrdata = decode(Image.open(imgpath))
	decodeqrdata=decodeqrdata[0].data.decode('ascii')
	labeldata=Label(root,text="the decoded data is:"+str(decodeqrdata))
	labeldata.pack()
	button_edit=Button(root,text="enter to edit the qrcode",command=editqr)
	button_edit.pack()
	
	
buttonqr=Button(root,text="enter to make qr",command=lambda:makeqr(root))
buttonqr.pack()
buttondeqr=Button(root,text="enter to decode any qrcode",command=lambda:decodeqr(root))
buttondeqr.pack()
root.mainloop()