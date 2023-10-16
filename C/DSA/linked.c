#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node *head,*newnode,*temp;
struct node *insertatfisrt (struct node *head,int data)
{
    printf("enter data");
    scanf("%d",&data);
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    printf("enter data");
    scanf("%d",&data);
    struct node *newnode;
    struct node *temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
struct node*insertafterpos(struct node*head,int data)
{
    int pos;
    int i=1;
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    struct node*temp=head;
    printf("enter data");
    scanf("%d",&newnode->data);
    printf("enter pos");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node *insertbeforepostion(struct node *head,int data)
{
    int pos;
    int i=1;
    struct node*newnode;
    struct node*temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    printf("enter pos");
    scanf("%d",&pos);  
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node*delfrombeg (struct node*head)
{
    struct node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node *delfromend (struct node*head)
{
    struct node *temp=head;
    struct node *last=head->next;
    while(last->next!=NULL)
    {
        temp=temp->next;
        last=last->next;
    }
    temp->next=NULL;
    free(last);
    return head;
}
struct node *delbeforepos (struct node*head)
{
    struct node *temp=head;
    struct node *last=head->next;
    int pos;
    int i=1;
    printf("enter the position");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        last=last->next;
        i++;
    }
    temp->next=last->next;
    free(last);
    return head;
}
struct node *delafterpos(struct node *head)
{
    struct node *temp=head;
    struct node *last=head->next;
    int pos;
    int i=1;
    printf("enter the position");
    scanf("%d",&pos);
    while(i<pos && last->next!=NULL)
    {
        temp=temp->next;
        last=last->next;
        i++;
    }
    temp->next=last->next;
    free(last);
    return head;
}
int main()
{
    int ch;
    head=NULL;
    while(1)
    {
        menu :
        printf("1 for creation of the linked list\n");
        printf("2 for insertion at the begining\n");
        printf("3 for insert at end\n");
        printf("4 for insert after pos\n");
        printf("5 for insert before pos\n"); 
        printf("6 for deletion from beginning\n");
        printf("7 for deletion from end\n");
        printf("8 for deletion before pos\n");
        printf("9 for deletion after pos\n");
        printf("10 for exit");
        printf("enter choice\n");
        scanf("%d",&ch);
        if(ch==0)
        {
        break;
        }
        else if(ch==1)
        {
        newnode=(struct node*)malloc(sizeof (struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        }
        else if(ch==2)
        {
            head=insertatfisrt(head,0);
        }
        else if(ch==3)
        {
            head=insertatend(head,0);
        }
        else if(ch==4)
        {
            head=insertafterpos(head,0);
        }
        else if(ch==5)
        {
            head=insertbeforepostion(head,0);
        }
        else if(ch==6)
        {
            head=delfrombeg(head);
        }
        else if(ch==7)
        {
            head=delfromend(head);
        }
        else if(ch==8)
        {
            head=delafterpos(head);
        }
        else if(ch==9)
        {
            head=delbeforepos(head);
        }
        else if (ch==10)
        {
            exit(0);
        }
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    goto menu;
}