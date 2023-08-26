a=float(input("Enter A No :"))
b=float(input("Enter A No :"))

print("Choose Operation")
print("Addition = 1")
print("Subtraction = 2")
print("Multiplication = 3")
print("Division = 4")

c=int(input("Enter Operation No :"))

d=a+b
e=a-b
f=a*b
g=a/b

if c==1:
    print(d)
if c==2:
    print(e)
if c==3:
    print(f)
if c==4:
    print(g)
