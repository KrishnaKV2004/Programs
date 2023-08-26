m=float(input("Max Marks : "))

P=float(input("Marks In Physics : "))
C=float(input("Marks In Chemistry : "))
M=float(input("Marks In Maths : "))
E=float(input("Marks In English : "))
I=float(input("Marks In IP : "))

t=P+C+M+E+I
a=(t/(m*5))*100

print("Total Marks :",t)
print("Percentage :",a)