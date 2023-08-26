#include <stdio.h>

int main()
{
    // Single Line Comment
    /* Multiple Line Comment */

    // Storing Variables In Diff Data Types -->
    int name; // Value assigned to store input value in future
    int age = 18;
    char star = '*';
    float pi = 3.14;

    // We can declare multiple variables and can store same or diff values -->
    int a, b, c;
    a = b = c = 5;
    // Or
    int x, y, z;
    x = 1;
    y = 2;
    z = 3;
    // Can't declare and use variables at the same time

    int k, s;
    int d, f = k + s;
    // Value of k + s will be stored in f not d !!

    // To Print Strings -->
    printf("Hello There \n"); // \n To print in new line
    printf("How Are You \n");

    // To Print Variables -->
    printf("Age iS :%d \n", age); // For Integer - %d
    printf("Pi iS :%f \n", pi);   // For Real No. - %f
    printf("Star :%c \n", star);  // For Character. %c

    // To Take Input -->
    printf("Enter Your Name :\n"); // To display message to the user to input
    scanf("%d", &name);
    printf("Name : %d \n", name); // To display the name
    /* Here %d means we are taking input as int
    And &age means we are storing it in age variable */

    return 0;
}