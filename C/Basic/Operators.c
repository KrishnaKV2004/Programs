//  Operators -->

#include <stdio.h>
#include <math.h>

// Should Be Included If using functions of Math Library

int main()
{
    /* 
       Operators -->
       •  Arithmetic Operators
       •  Relational Operators
       •  Logical Operators
       •  Bitwise Operators
       •  Assignment Operators
       •  Ternary Operators
    */
    /*
        Arithmetic Operators -->
        • Addition (+)
        • Subtraction (-)
        • Multiplication (*)
        • Division (/)
        • Modulo (%)
    */
        int a, b;

        printf("Enter No. A : ");
        scanf("%d", &a);

        printf("Enter No. B : ");
        scanf("%d", &b);

        printf("A + B : %d \n", a+b);
        printf("A - B : %d \n", a-b);
        printf("A * B : %d \n", a*b);
        printf("A / B : %d \n", a/b);
        printf("A % B : %d \n", a%b);
    
    //  Power Operator -->
    //  • v = pow(a,b)

        int k = pow(a,b);
        printf("A ^ B : %d \n", k);
    /*
        Arithmetic Instructions -->

        * Operator Precedence -->
          • *, /, %
          • +, -
          • =
        # If operators are of same precedence operation will be Associative
    */
        int d, e, f;
        printf("Enter No. D : ");
        scanf("%d", &d);
        printf("Enter No. E : ");
        scanf("%d", &e);
        printf("Enter No. F : ");
        scanf("%d", &f);

        printf("D*E/F*E : %d\n", d*e/f*e);
        printf("D*E+F/E : %d\n", d*e+f/e);
    /*
        Control Instructions -->
          • Sequence Control
          • Decision Control
          • Loop Control
          • Case Control
    
        Relational Operators -->
          • ==      * To check Equality
          • >, >=   * To check if no A is greater than or equal to B or not
          • <, <=   * To check if no A is less then or equal to B or not
          • !=      * To check Inequality
        # If True -->  It will return 1
        # If False --> It will return 0
    */
        int x, y, z;
        x = 2;
        y = z = 1;
        printf("Relational Test :\n");
        printf("%d\n", x==y);
        printf("%d\n", z==y);
        printf("%d\n", x>=y);
        printf("%d\n", x!=y);
    /*
        Logical Operators -->
        # To check for more than one Condition :
          • &&  And  [All Statements should be correct to print True]
          • ||  Or   [At least one statement should be correct to print True]
          • !   Not  [To print the reverse of the given statement]
    */
        printf("Logical Test :\n");
        printf("%d\n", d>e && f<d);
        printf("%d\n", d>e || f<d);
        printf("%d\n", !(d>e));
        printf("%d\n", !(d>e && f>e));
    /*
        Precedence when Arithmetic, Relational and Logical operators come simultaneously -->
        Example --> (a+b/c*d) > (e/f*c) == (a*b/f+d*e)

        Precedence :
        Priority        Operator
           1               !
           2             *,/,%
           3              +,-
           4           <,<=,>,>=
           5             ==,!=
           6               &&
           7               ||
    */
    /*
        Assignment Operators [ Short Hand Operators] -->
          • =   [a=b]
          • +=  [a+=b] Instead Of [a=a+b]
          • -=  [a-=b] Instead Of [a=a-b]
          • *=  [a*=b] Instead Of [a=a*b]
          • /=  [a/=b] Instead Of [a=a/b]
          • %=  [a%=b] Instead Of [a=a%b]
    */
    /*
        Conditional Operators -->
          • IF-Else
          • Switch
          • Ternary
    */
    /*
        To Check for Multiple Statements -->

        if (Condition 1)
        {
            // Do something if true ;
        }
        else if (Condition 2)
        {
            // Do something if 1st is False and 2nd is True ;
        }
        else (Final Condition)
        {
            // Do something if all above statements are False ;
        }

        // If there is one statement, Curly Braces can be skipped
    
        If given condition are't affected by the above conditions -->
        Use if statement again to check again
        Otherwise else or else if ;
    */
        int age;
        printf("Enter Your Age : ");
        scanf("%d", &age);

        if (age >= 18)
        {
            printf("Adult\n");
        }
        else if (age > 13 && age < 18)
        {
            printf("Teenager\n");
        }
        else
        {
            printf("Child\n");
        }
    /*
        Ternary Operators [To Make The Code Shorter] -->
        • Used if there is only one condition to check
        • Syntax ->
          Condition ? Do something if True : Do something if False ;
   */
        age >= 18 ? printf("Adult\n") : printf("Child\n") ;
    /*
        Switch -->
        Syntax ->
        switch (number/character)
        {
            case C1 : // Do something
                      break;
            case C2 : // Do something
                      break;
            default : // Do something
        }
        # If case is no. syntax -> case no.
        # If case is char syntax -> case 'char'
        # If you want to execute all the cases after the matching switch, remove break;

        Properties OF Switch -->
        • Cases can be in any order
        • Nested switches (switch inside a switch) are allowed
    */  
    //  Example of Nested If Statement -->

        int num;
        printf("Enter Number : ");
        scanf("%d", &num);

        if (num >= 0)
        {
            printf("Positive\n");
            if (num % 2 == 0)
            {
                printf("Even\n");
            }
            else
            {
                printf("Odd\n");
            }
        }
        else
        {
            printf("Negative\n");
            if (num % 2 == 0)
            {
                printf("Even\n");
            }
            else
            {
                printf("Odd\n");
            }
        }
        
        return 0;
}