#include <stdio.h>
/*
    Function -->
    A block of code that perform a particular task
    Take Input -> Perform Task -> Give Output
#   Increase the reusability
#   Can be used multiple times
#   Takes value (Parameter), Gives output (Return value)
*/
/*  Syntax 1 -->
    Function Declaration
*/
void printHello();
// # Void means empty, it will not return anything ->

/*  Syntax 3 -->
    Function Call
*/
int main()
{
    printHello();
    return 0;
}
/*  Syntax 2 -->
Function Definition
*/
void printHello()
{
    printf("Hello");
}
/*  Properties -->
    • Execution always starts from main
    • A function gets called directly or indirectly from main
    • There can be multiple functions in the program

    Function Types -->
    Library Functions - Inbuilt Functions
    User Defined - Functions Defined By Us

    Passing Arguments -->
    void fname();
    void fname(int a);
    datatype fname (int a, int b); // datatype - return value type
*/
/*  Example of 3rd Passing argument ->
    Declaration ->
    int sum(int a, int b);
    Definition ->
    int sum(int a, int b) {
        return a+b;
    }
    Call ->
    int s = sum(a,b); # inside main function
    printf("Sum is : %d", s);
*/