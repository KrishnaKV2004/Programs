print("List 1")
a=int(input("Enter Element 1 :"))
b=int(input("Enter Element 2 :"))
c=int(input("Enter Element 3 :"))
d=int(input("Enter Element 4 :"))
e=int(input("Enter Element 5 :"))
ls1=[a,b,c,d,e]

print("List 2")
f=int(input("Enter Element 1 :"))
g=int(input("Enter Element 2 :"))
h=int(input("Enter Element 3 :"))
i=int(input("Enter Element 4 :"))
j=int(input("Enter Element 5 :"))
ls2=[f,g,h,i,j]

import matplotlib.pyplot as plt

plt.bar(ls1,ls2)
plt.title("Bar Graph")
plt.xlabel("Class")
plt.ylabel("Students")
plt.show