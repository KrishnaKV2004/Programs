#include <stdio.h>

int main()
{
    /*
    Loop Control Instructions -->
    # Use -> To Repeat Actions
    Types ->
    • For Loop
    • While Loop
    • Do While Loop
    */
    /*
    For Loop -->
    Syntax ->
    for (Initialisation/Declaration; Condition/Termination; Updation) {
        // Do Something
    }
    Initialisation --> To start a task
    For Ex -> int i=1
    Condition --> To end a task
    For Ex -> i<=5
    Updation --> To update a task
    For Ex -> i=i+1
    # We can use i+=1 instead of i=i+1 as we learnt in Assignment Operators
    # We can also use i++ instead of i=i+1 only if we are adding 1
    # Iterator - The starting value defined
    */
    // To Print Hello World 2 Times -->
    for (int i=1; i<=2; i++)
    {
        printf("Hello World\n");
    }
    // To Print Numbers From 1 to 10 -->
    for(int i=1; i<=10; i+=1)
    {
        printf("%d\n", i);
    }
    // To Print Numbers In Descending Order -->
    for (int i=10; i>=1; i=i-1){
        printf("%d\n", i);
    }
    // Multiple variables can be initialised in loop
    
    // To calculate sum of first (n) numbers and print them in reverse -->

    int n;
    printf("Enter No : ");
    scanf("%d", &n);
    int sum=0;
    for (int i=1,j=n; i<=n && j>=1; i++,j--) {
        sum += i;
        printf("%d\n", j);
    }
    printf("Sum is : %d\n", sum);

    /*
    Special Things -->
    • Increment Operator
    • Decrement Operator
    • Loop Counter [can be float or even character]
    • Infinite Loop

    # Increment Operator ->
    • i++ (First Use i then increase)
    • ++i (First increase then use i)

    # Decrement Operator ->
    • i-- (First use i then decrease)
    • --i (First decrease then use i)

    # Loop Counter ->
    Integer, Float and Characters can be printed in loop by using int float and char with Iterator

    # Infinite Loop ->
    If condition is missed in the for syntax, Infinite Loop will execute
    Never use Infinite Loop, It will run till it occupies the whole memory and will crash

    While Loop -->
    Syntax ->
    initialisation/declaration
    while (condition/termination)
    {
        // Do Something
        Updation
    }
    # We should declare the variable first before using while loop
    */
    int i=1;
    while (i<=5) {
        printf("%d", i);
        i++;
    }
    /*
    Do While Loop -->
    Syntax ->
    do {
        // do something
    } while (condition);

    # Runs atleast 1 time even if the condition is False, then condition is checked
    # Preferred to take input from user 
    */
    return 0;
}