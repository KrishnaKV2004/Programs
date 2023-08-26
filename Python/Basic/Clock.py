import string
from tkinter import *
from tkinter.tix import LabelEntry
from tkinter.ttk import *

from time import strftime

root = Tk()
root.title("Clock")

def time():
    string = strftime('%H:%M:%S %p')
    label.config(text=string)
    label.after(1000, time)

label = Label(root, font=("micross", 80), background="black" , foreground="White" )
label.pack(anchor='center')

time()

mainloop()