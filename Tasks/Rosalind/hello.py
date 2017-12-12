from Tkinter import *
 
root = Tk()
 
but = Button(root,
          text="Это кнопка", #надпись на кнопке
          width=30,height=5, #ширина и высота
          bg="white",fg="blue") #цвет фона и надписи

lab = Label(root, text="Это метка! \n Из двух строк.", font="Arial 18")

ent = Entry(root,width=20,bd=3)

tex = Text(root,width=40,
          font="Verdana 10",
          wrap=WORD)

var=IntVar()
var.set(1)
rad0 = Radiobutton(root,text="Первая",
          variable=var,value=0)
rad1 = Radiobutton(root,text="Вторая",
          variable=var,value=1)
rad2 = Radiobutton(root,text="Третья",
          variable=var,value=2)

c1 = IntVar()
c2 = IntVar()
che1 = Checkbutton(root,text="Первый флажок",
          variable=c1,onvalue=1,offvalue=0)
che2 = Checkbutton(root,text="Второй флажок",
          variable=c2,onvalue=2,offvalue=0)

r = ['Linux','Python','Tk','Tkinter']
lis = Listbox(root,selectmode=SINGLE,height=4)
for i in r:
     lis.insert(END,i)

lab.pack()
but.pack()
ent.pack()
tex.pack()
rad0.pack()
rad1.pack()
rad2.pack()
che1.pack()
che2.pack()
lis.pack()

root.mainloop()
