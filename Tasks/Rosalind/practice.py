from Tkinter import *

root = Tk()

lab_adr = Label(root, text="��� �����:")
ent = Entry(root, width=20, bd=3)
lab_kom = Label(root, text="�����������:")
tex = Text(root, width=40,
           height=10)
btn = Button(root,
             text="���������",
             width=30, height=5,
             bg="cyan", fg="black")
lab_count = Label(root, text="������� ����?")
var = IntVar()
var.set(0)
rad0 = Radiobutton(root, text="0-10",
                   variable=var, value=0)
rad1 = Radiobutton(root, text="11-20",
                   variable=var, value=1)
rad2 = Radiobutton(root, text="21-30",
                   variable=var, value=2)
rad3 = Radiobutton(root, text="31-40",
                   variable=var, value=3)
lab_color = Label(root, text="������ �����?")
c1 = IntVar()
c2 = IntVar()
c3 = IntVar()
c4 = IntVar()
che1 = Checkbutton(root, text="RED",
                   bg="red", variable=c1, onvalue=1, offvalue=0)
che2 = Checkbutton(root, text="BLUE",
                   bg="blue", variable=c2, onvalue=2, offvalue=0)
che3 = Checkbutton(root, text="GREEN",
                   bg="green", variable=c3, onvalue=3, offvalue=0)
che4 = Checkbutton(root, text="YELLOW",
                   bg="yellow", variable=c4, onvalue=4, offvalue=0)

lab_adr.pack()
ent.pack()
lab_kom.pack()
tex.pack()
btn.pack()
lab_count.pack()
rad0.pack()
rad1.pack()
rad2.pack()
rad3.pack()
lab_color.pack()
che1.pack()
che2.pack()
che3.pack()
che4.pack()

root.mainloop()
