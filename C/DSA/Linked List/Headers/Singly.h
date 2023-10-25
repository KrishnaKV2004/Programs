typedef struct Node
{
    int data;               //  Integer Variable To Store Data
    struct Node * next;     //  Self Referencing Pointer To Store Address Of Next Node
} nd;

//  Function Declaration-->

nd * f_ins(nd *);             //  To Insert Node At First Position
nd * l_ins(nd *);             //  To Insert Node At Last Position
nd * s_ins(nd *);             //  To Sort The List While Inserting
nd * c_ins(nd *, int);        //  To Insert Node At Custom Position

nd * f_del(nd *);             //  To Delete First Node Of Linked List
nd * l_del(nd *);             //  To Delete Last Node Of Linked List
nd * c_del(nd *, int);        //  To Delete Node From Custom Position
nd * a_del(nd *, int *);      //  To Delete Alternate Nodes In The List

nd * rev(nd *);               //  To Reverse The Linked List
nd * rotate(nd *, int);            //  To Rotate The Linked List

void f_view(nd *);            //  To View Full Data In Linked List
void c_view(nd *, int);       //  To View Specific Node Data In Linked List

void nd_cn(int);              //  To Display Number Of Nodes In Linked List
void sort(nd *);              //  To Sort The Linked List
void middle(nd *, int);       //  To Display The Middle Node Of Linked List

//  Function Definition -->

nd * f_ins(nd *head)
{
    int val;                                    //  To Store Data Value
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New Node Allocation

    //  Checking If Memory Is Allocated
    if (new_node == NULL)
    {
        //  If Memory Not Allocated
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    //  Input Value To Store
    printf("Enter Data --> ");
    scanf("%d", &val);

    //  Joining New Node And Updating Head
    new_node->data = val;
    new_node->next = head;
    head = new_node;

    return head;
}

nd * l_ins(nd *head)
{
    int val;                                    //  To Store Data Value
    nd *temp = head;                            //  Temp Pointer To Traverse To The Last Node
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New Node Allocation

    //  Checking If Memory Is Allocated
    if (new_node == NULL)
    {
        //  If Memory Not Allocated
        printf("\nSorry ! Memory Not Allocated\n");
        return head;
    }

    printf("Enter Data --> ");
    scanf("%d", &val);

    //  Checking If There Is No Node
    if (head == NULL)
    {
        //  Updating New Node With Head Info
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    //  If Nodes Exists Already
    else
    {
        //  Traversing To The Last Node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        //  Updating New Node With Help Of Temp Info
        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

nd * c_ins(nd *head, int node_count)
{
    int i,val,indx;                             //  To Iterate, Store Value And Index
    nd *exc = head;                             //  To Exchange Address With Temp Node
    nd *temp = head->next;                      //  To Traverse To Specific Node
    nd *new_node = (nd *)malloc(sizeof(nd));    //  New node To Insert

    //  Input Index To Insert Node
    printf("\nEnter Place To Insert Node --> ");
    scanf("%d", &indx);

    //  Checking -ve Index Condition
    if (indx<=0)
    {
        printf("\nInvalid Index ! [Out Of Bound]\n");
        return head;
    }

    //  Checking First Node Condition
    if (indx == 1)
    {
            //  Function To Insert Node At Index 1 
            head = f_ins(head);
    }

    //  Checking If Index Is Last Node
    if (indx == (node_count+1))
    {
        head = l_ins(head);
        return head;
    }

    //  Checking If Index Exceeds Node
    if (indx > node_count)
    {
        printf("\nInvalid Index [Out Of Bound]\n");
        return head;
    }

    //  Inserting Nodes in Between
    else
    {
        printf("\nEnter Data --> ");
        scanf("%d", &val);

        for (i=1; i<indx-1; i++)
        {
            //  Traversing To Specified Node
            temp = temp->next;
            exc = exc->next;
        }

        //  Updating Address Of Node
        new_node->data = val;
        new_node->next = exc->next;
        exc->next = new_node;
    }

    return head;
}

nd * s_ins(nd *head)
{
    int val;
    nd *temp = head;
    nd *new_node = (nd *)malloc(sizeof(nd));

    //  If Memory Not Allocated
    if (new_node == NULL)
    {
        printf("\nSorry! Memory Not Allocated\n");
        return head;
    }

    printf("\nEnter Data --> ");
    scanf("%d", &val);

    new_node->data = val;
    new_node->next = NULL;

    //  If No Node Exist Or Value Is Smaller
    if (head == NULL || val <= head->data)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        while (temp->next != NULL && temp->next->data < val)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    //  Function Call To View Sorted Linked List
    f_view(head);

    return head;
}

nd * f_del(nd *head)
{
    //  Checking If List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *temp = head;        //  Temp Pointer To Traverse

    //  Updating Head With Next Node And Deleting Temp
    head = head->next;
    free(temp);

    return head;
}

nd * l_del(nd *head)
{
    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *temp = head;         //  Temp Pointer To Traverse
    nd *exc = head->next;    //  Fr Pointer Pointing Next Node Of Temp

    //  Traversing Fr To Last Node
    while (exc->next != NULL)
    {
        //  Updating Temp And Fr To Last Node
        temp = temp->next;
        exc = exc->next;
    }

    //  Assigning NULL To Second Last Node And Deleting Last Node
    temp->next = NULL;
    free(exc);

    return head;
}

nd * c_del(nd *head, int node_count)
{
    int i, indx;    //  To Iterate And Store Index

    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty\n");
        return head;
    }

    nd *exc = head;
    nd *temp = head->next;

    printf("\nNode To Delete ? --> ");      //  Input Node To Delete
    scanf("%d", &indx);                     //  Store Input In Variable

    //  If Index Is Zero
    if (indx<=0)
    {
        printf("\nInvalid Index ! [No Such Node]\n");
        return head;
    }

    //  If Index Is 1
    else if (indx == 1)
    {
        head = f_del(head);     //  Function To Delete First Node
    }

    //  If Index Exceeding Last Node 
    else if (indx > node_count)
    {
        printf("\nInvalid Index ! [Node Doesn't Exist]\n");
        return head;
    }

    //  If Index Is Out Of Bound
    else if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid Index ! [Out Of Bound]\n");
        return head;
    }

    else
    {
        for (i=1; i<indx-1; i++)
        {
            //  Traversing To The Specific Index
            temp = temp->next;
            exc = exc->next;
        }

        //  Updating Node Address And Deleting Node
        exc->next = temp->next;
        free(temp);
    }

    return head;
}

nd* a_del(nd *head, int *node_count)
{
    //  Checking If The List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty!\n");
        return head;
    }

    //  To Track Nodes
    nd* curr = head;
    nd* nxt = head->next;
    nd* prev = NULL;

    while (curr != NULL && nxt != NULL)
    {
        // Remove the current node
        curr->next = nxt->next;
        free(nxt);
        (*node_count)--;

        // Move to the next pair of nodes
        prev = curr;
        curr = curr->next;

        if (curr != NULL)
        {
            nxt = curr->next;
        }
        else
        {
            nxt = NULL;
        }
    }

    //  Function Call To Display Linked List
    f_view(head);
    
    return head;
}

nd * rev(nd *head)
{
    char see;       //  To See Reversed Linked List

    //  Checking If List Is Empty
    if (head == NULL)
    {
        printf("\nNo Nodes To Reverse !\n");
        return head;
    }

    //  To Point To Different Nodes To Exchange
    nd *prev,*curr,*nxt;
    prev=NULL;              
    curr=nxt=head;

    while(nxt!=NULL)
    {
            //  Traversing The List
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
    }

    //  Assigning Head
    head = prev;

    printf("\nLinked List Reversed Successfully !\n");

    //  Function Call To View Reversed Linked List
    f_view(head);

    return head;
}

void f_view(nd *head)
{
    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    while (head != NULL)
    {
        //  Traversing Linked List And Printing Data
        printf("\nData --> %d", head->data);
        head = head->next;  //  Moving To Next Node
    }

    printf("\n");
}

void c_view(nd *head, int node_count)
{
    int i, indx;        //  To Iterate And Store Index
    nd *temp = head;    //  To Traverse To Specific Node

    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    printf("\nEnter Index To View Node Data --> ");
    scanf("%d", &indx);

    if (indx<=0 || indx>node_count)
    {
        printf("\nInvalid Node !\n");
        return;
    }

    for (i=1; i<indx; i++)
    {
        //  Traverse To Specified Node
        temp = temp->next;
    }

    //  Printing Data At Specified Node
    printf("\nData --> %d\n", temp->data);
}

void nd_cn(int node_count)
{
    //  Display Number Of Nodes
    printf("\nNodes --> %d\n", node_count);
}

void middle(nd *head, int node_count)
{
    int position = 0;       //  To Track Position

    //  Checking If List Is Empty
    if (node_count == 0)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    //  If Number Of Nodes Are Even
    if (node_count%2==0)
    {
        printf("\nNo Middle Node Found !\n");
        return;
    }
    else
    {
        //  Finding The Middle Node
        while(position<(node_count/2))
        {
            head = head->next;
            position++;
        }

        printf("\nMiddle Node Data --> %d\n", head->data);
    }
}

void sort(nd *head)
{
    int swap;               //  To Swap Data
    nd *nxt = NULL;         //  To Point To Next Node
    nd *curr = NULL;        //  To Point To Current node

    //  Checking If List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return;
    }

    //  Traversing The Next Node And Scanning With Current Then Update Current
    for (curr=head; curr!=NULL; curr=curr->next)
    {
        for (nxt=curr->next; nxt!=NULL; nxt=nxt->next)
        {
            if ((nxt->data)<(curr->data))
            {
                swap = curr->data;
                curr->data = nxt->data;
                nxt->data = swap;
            }
        }
    }
    printf("\nLinked List Sorted !\n");

    //  Function Call To View Sorted Linked List
    f_view(head);
}

nd * rotate(nd *head, int node_count)
{
    int iterate;            //  To Iterate Loop
    int rotate_num;         //  To Store Rotating Number
    nd *temp = head;        //  To Traverse Upto Rotating Number
    nd *last = head;        //  To Traverse To The Last Node

    //  Checking If Linked List Is Empty
    if (head == NULL)
    {
        printf("\nLinked List Is Empty !\n");
        return head;
    }

    //  Scanning Rotating Number
    printf("\nEnter Rotating Number --> ");
    scanf("%d", &rotate_num);

    //  Checking if Rotating Number Is Zero
    if (rotate_num == 0)
    {
        printf("\nNo Nodes To Rotate !\n");
        f_view(head);

        return head;
    }
 
    //  Checking If Rotating Number Is More Than Nodes
    if (rotate_num > node_count)
    {
        //  Using Modulo Of Rotating Number With Node Count
        rotate_num = rotate_num % node_count;
    }

    //  Traverse Temp Upto The Shifting Data
    for (iterate = 1; iterate < (node_count - rotate_num); iterate++)
    {
        temp = temp->next;
    }

    //  Traverse Last To The Last Node
    while (last->next!=NULL)
    {
        last = last->next;
    }

    //  Changing Links Of Node
    last->next = head;
    head = temp->next;
    temp->next = NULL;

    //  Display The Rotated Linked List
    printf("\nLinked List Rotated Successfully !\n");
    f_view(head);

    return head;
}