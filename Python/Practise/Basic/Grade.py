marks = float(input("Enter Marks : "))

if marks > 90 :
    print("Grade --> A")
    
elif marks > 80 and marks <= 90 :
    print("Grade --> B")
    
elif marks >= 60 and marks <=80 :
    print("Grade --> C")
    
else :
    print("Grade --> D")