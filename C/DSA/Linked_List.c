#include <stdio.h>
typedef struct list
{
    int data;
    struct list *next;
} ls;

ls ins();
ls del();
ls view();
ls peek();

int main()
{
    ls *p = NULL;
    ls *R = NULL, *L = NULL;
    char ch, con;

    menu :

        printf("\nEnter [I] To Insert Element");
        printf("\nEnter [D] To Delete Element");
        printf("\nEnter [V] To View Elements");
        printf("\nEnter [P] To Peek Element");
        printf("\n\nEnter Choice : ");
        scanf(" %c",&ch);

        switch (ch)
        {
            case 'I' :
            case 'i' :
            
                break;

            case 'D' :
            case 'd' :

                break;

            case 'V' :
            case 'v' :

                break;

            case 'P' :
            case 'p' :

                break;

            default:
                break;
        }

        printf("\nDo You Want To Continue ? [Y/N] : ");
        scanf(" %c",&con);

        if (con == 'y' || con == 'Y')
        {
            goto menu;
        }
        else
        {
            exit;
        }

    return 0;
}

ls ins()
{

}

ls del()
{

}

ls view()
{

}

ls peek()
{
    
}