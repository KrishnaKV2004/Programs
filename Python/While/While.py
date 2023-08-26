# Break terminates the loop
# Continue sends control to the next iteration

def even():
    num = int(input("Enter Number : "))
    i = 2
    while i <= num:
        print(i)
        if i>=6:
            break
        i = i + 2
even()
