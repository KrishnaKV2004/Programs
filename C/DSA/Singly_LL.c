 //  Implementation Of Singly Linked List

//  Header Files -->

#include <stdio.h>
#include <stdlib.h>

//  Node Structure To Store Data + Address-->

typedef struct Node
{
    int data;               //  Integer Variable To Store Data
    struct Node * next;     //  Self Referencing Pointer To Store Address Of Next Node
} nd;

//  Function Declaration-->

nd* f_ins(nd*);     //  To Insert Node At First Position
nd* c_ins(nd*);     //  To Insert Node At Custom Position
nd* l_ins(nd*);     //  To Insert Node At Last Position

nd* f_del(nd*);     //  To Delete First Node Of Linked List
nd* c_del(nd*);     //  To Delete Node From Custom Position
nd* l_del(nd*);     //  To Delete Last Node Of Linked List

void f_view(nd*);    //  To View Full Data In Linked List
void c_view(nd*);    //  To View Specific Node Data In Linked List

//  Main Function -->

int main()
{
    nd *head = NULL;   //  To Store Address Of First Node
    int cus_nd;        //  To Store Position To Insert / Delete From
    char con, pos, choice;   //  To Input Operation Choice And Continue / End And Position To Insert / Delete

    //  Menu For Operations -->

    printf("\n# -------- Linked List -------- #\n");

    menu :

        printf("\nOperations ---->\n");
        printf("\n[I] To Insert Node");
        printf("\n[D] To Delete Node");
        printf("\n[V] To View Data");
        printf("\n\nChoose Operation ----> ");
        scanf(" %c", &choice);

        //  Checking For Operation Cases -->

        switch (choice)
        {
            //  To Insert -->

            case 'I' :
            case 'i' :

                //  Checking Further Possibilities -->

                printf("\nChoose Place To Insert ---->\n");
                printf("\n[F] To Insert At First Position");
                printf("\n[L] To Insert At Last Position");
                printf("\n[C] To Insert At Custom Position");
                printf("\n\nChoose Operation --> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    //  To Insert At First Position -->

                    case 'F' :
                    case 'f' :

                        //  Function To Insert Node At First Position
                        head = f_ins(head);
                        break;

                    //  To Insert At Last Position -->

                    case 'L' :
                    case 'l' :

                        //  Function To Insert Node At Last Position
                        head = l_ins(head);
                        break;

                    //  To Insert At Custom Position -->

                    case 'C' :
                    case 'c' :

                        //  Function To Insert Node At Specific Position
                        head = c_ins(head);
                        break;

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        break;
                }
                break;

            //  To Delete -->

            case 'D' :
            case 'd' :

                //  Checking Further Possibilities -->

                printf("\nChoose Place To Delete ---->\n");
                printf("\n[F] To Delete First Node");
                printf("\n[L] To Delete Last Node");
                printf("\n[C] To Delete Custom Node");
                printf("\n\nChoose Operation --> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    //  To Delete First Node -->

                    case 'F' :
                    case 'f' :

                        //  Function To Delete First Node
                        head = f_del(head);
                        break;

                    case 'L' :
                    case 'l' :

                        //  Function To Delete Last Node
                        head = l_del(head);
                        break;

                    case 'C' :
                    case 'c' :

                        //  Function To Delete Custom Node
                        head = c_del(head);
                        break;

                    default:

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        break;
                }
                break;

            //  To View Data Of Linked List -->

            case 'V' :
            case 'v' :

                //  Checking For Further Viewing Possibilities -->

                printf("\nChoose Operation To View ---->\n");
                printf("\n[A] To View All Data In Linked List");
                printf("\n[N] To View Data Of Specific Node");
                printf("\n\nChoose Operation --> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    //  To View Entire Linked List -->

                    case 'A' :
                    case 'a' :

                        //  Function To view Entire Linked List
                        f_view(head);
                        break;

                    //  To View Data At A Specific Node
                    case 'N' :
                    case 'n' :

                        //  Function To View Data At Specific Node
                        c_view(head);
                        break;

                    default :

                        //  Message For Invalid Input Choice
                        printf("\nInvalid Operation !");
                        break;
                }    
                break;

            default :

                //  Message For Invalid Input Choice
                printf("\nInvalid Operation !\n");
                break;
        }

        //  To Continue Operations -->

        printf("\nContinue Operation ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con=='Y' || con=='y')
        {
            goto menu;  //  If True Goto Menu
        }
        else
        {
            exit(0);    //  Else Exit
        }

    return 0;
}

//  Function Definition -->

nd* f_ins(nd *head)
{
    int val;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        //  If Memory Not Allocated
        printf("\nSorry ! Memory Not Allocated");
        return head;
    }

    //  Input Value To Store
    printf("\nEnter Data --> ");
    scanf("%d", &val);

    //  Joining New Node And Updating Head
    new_node->data = val;
    new_node->next = head;
    head = new_node;

    return head;
}

nd* l_ins(nd *head)
{
    int val;
    nd *temp;
    nd *new_node = (nd *)malloc(sizeof(nd));

    if (new_node == NULL)
    {
        printf("\nSorry ! Memory Not Allocated");
        return head;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    if (head == NULL)
    {
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

nd* c_ins(nd *head)
{

}

nd* f_del(nd *head)
{

}

nd* l_del(nd *head)
{

}

nd* c_del(nd *head)
{
    
}

void f_view(nd *head)
{
    while (head != NULL)
    {
        //  Traversing Linked List And Printing Data
        printf("\nData --> %d", head->data);
        head = head->next;  //  Moving To Next Node
    }

    printf("\n");
}

void c_view(nd *head)
{

}