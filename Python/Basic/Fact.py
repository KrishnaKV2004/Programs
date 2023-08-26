#   Program to find factorial of a number

n = int(input("Enter Number : "))

fact = n

if n==0 :
    print("1")
else :
    for i in range (n-1,0,-1) :
        fact = fact * i
    
    print(fact)