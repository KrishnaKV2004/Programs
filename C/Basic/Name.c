#include <stdio.h>

void main()
{
    //  Declaring Array
    int n;
    char a[20];

    //  Input Name
    printf("\nEnter Your Name : ");
    for (int i=0; i<20; i++)
    {
        scanf("%c",&a[i]);
        if (a[i]=='\n')
        {
            break;
        }
    }

    //  Counting Length Of First Name
    int ch,nv=0,nc=0;
    for (int i=0; a[i]!=' '; i++)
    {
        nc++;
    }

    //  Menu To Perform Tasks
    printf("\nEnter (1) To Print Initials\n");
    printf("Enter (2) To Count Vowels\n");
    printf("Enter (3) To Capitalize Name\n");
    printf("Enter (N) To Exit\n");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
    
        //  Printing Initials
        for (int i=0; i<n; i++)
        {
            if (a[i]>'a' && a[i]<'z')
            {
                printf("\nInitials : %c.%c.\n", a[0]-32, a[nc+1]-32);
                break;
            }
            else if (a[i]>'A' && a[i]<'Z')
            {
                printf("\nInitials : %c.%c.\n", a[0], a[nc+1]);
                break;
            }
        }
        break;
    
    case 2:

        //  Counting Vowels
        for (int i=0; a[i]!='\n'; i++)
        {
            if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            {
                nv++;
            }
        }
        printf("\nNumber Of Vowels : %d\n",nv);
        break;

    case 3:

        //  Capitalizing Name
        for (int i=0; a[i]!='\n'; i++)
        {
            if (a[i]!=' ')
            {
            a[i] = a[i]-32;
            }
        }

        //  Printing Capitalized Name
        printf("\nCapitalized Name : ");
        for (int i=0; a[i]!='\n'; i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
        break;

    case 'N':
    case 'n':

        //  Exit
        printf("\nHave A Nice Day !\n");
        break;

    default:
        printf("Invalid Input !");
        break;
    }
}