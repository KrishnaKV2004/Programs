//  Header Files ---->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  Node Structure ---->

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} nd;

//  Function Declaration ---->

nd * insert(nd *, int);
nd * removeData(nd *, int);
nd * inOrder_predecessor(nd *);

void preOrder(nd *);
void inOrder(nd *);
void postOrder(nd *);

int minValue(nd *);
int maxValue(nd *);

void count_leafNodes(nd *, int *);
void count_leftChild(nd *, int *);
void count_rightChild(nd *, int *);
void count_bothChild(nd *, int *);

//  Main Function ---->

int main()
{
    int choice;

    nd *root = NULL;

    menu :

        system("cls");
        printf("\n#----- BINARY SEARCH TREE -----#\n");
        printf("\n           OPERATIONS           \n");
        printf("\n[1] To Insert Data In BST");
        printf("\n[2] To Delete Data From BST");
        printf("\n[3] To Traverse In BST");
        printf("\n[4] To Count Childs In BST");
        printf("\n[5] To Find Min/Max Elements");
        printf("\n[6] To Exit From The BST");
        printf("\n\nChoose Operation ----> ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                int value;
                printf("\nEnter Value To Insert --> ");
                scanf("%d", &value);
                root = insert(root, value);
                goto menu;

            case 2:

                int del_key;
                printf("\nEnter Value To Delete --> ");
                scanf("%d", &del_key);
                root = removeData(root, del_key);
                printf("\nKEY DELETED SUCCESSFULLY !");
                sleep(3);
                goto menu;

            case 3:

                int traverse_choice;

                traverse_menu :

                    system("cls");
                    printf("\n#----- TRAVERSAL IN BST -----#\n");
                    printf("\n[1] For Preorder Traversal");
                    printf("\n[2] For Inorder Traversal");
                    printf("\n[3] For Postorder Traversal");
                    printf("\n[4] To Go To Main Menu");
                    printf("\n\nChoose Traversal Method --> ");
                    scanf("%d", &traverse_choice);

                    switch (traverse_choice)
                    {
                        case 1:

                            printf("\nPreOrder Traversal ---->\n\n");
                            preOrder(root);
                            sleep(5);
                            goto traverse_menu;

                        case 2:

                            printf("\nInOrder Traversal ---->\n\n");
                            inOrder(root);
                            sleep(5);
                            goto traverse_menu;

                        case 3:

                            printf("\nPostOrder Traversal ---->\n\n");
                            postOrder(root);
                            sleep(5);
                            goto traverse_menu;

                        case 4:

                            goto menu;
                            break;

                        default :

                            printf("\nINVALID INPUT !");
                            sleep(3);
                            goto traverse_menu;
                    }

                break;

            case 4:

                int ln = 0;
                int lc, rc, bc = 0;
                int count_choice;

                count_menu :

                    system("cls");
                    printf("\n#----- CHILDS COUNT IN BST -----#\n");
                    printf("\n[1] To Count Leaf Nodes");
                    printf("\n[2] To Count Left Childs");
                    printf("\n[3] To Count Right Childs");
                    printf("\n[4] To Count Both Childs");
                    printf("\n[5] To Go To Main Menu");
                    printf("\n\nChoose Count Method --> ");
                    scanf("%d", &count_choice);

                    switch (count_choice)
                    {
                        case 1:

                            count_leafNodes(root, &ln);
                            printf("\nNumber Of Leaf Nodes --> %d", ln);
                            sleep(5);
                            goto count_menu;

                        case 2:

                            count_leftChild(root, &lc);
                            printf("\nNumber Of Nodes With Left Child --> %d", lc);
                            sleep(5);
                            goto count_menu;
                            
                        case 3:

                            count_rightChild(root, &rc);
                            printf("\nNumber Of Nodes With Right Child --> %d", rc);
                            sleep(5);
                            goto count_menu;

                        case 4:

                            count_bothChild(root, &bc);
                            printf("\nNumber Of Nodes With Both Childs --> %d", bc);
                            sleep(5);
                            goto count_menu;
                        
                        case 5:

                            goto menu;

                        default :

                            printf("\nINVALID INPUT !");
                            sleep(3);
                            goto count_menu;
                    }

                break;

            case 5:

                int min;
                int max;
                int min_max_choice;

                min_max_menu :

                    system("cls");
                    printf("\n#----- MIN/MAX ELEMENTS -----#\n");
                    printf("\n[1] To Find Minimum Element");
                    printf("\n[2] To Find Maximum Element");
                    printf("\n[3] To Go To Main Menu");
                    printf("\n\nChoose Option --> ");
                    scanf("%d", &comp_choice);

                    switch (min_max_choice)
                    {
                        case 1:

                            min = minValue(root);
                            printf("\nMinimum Element --> %d", min);
                            sleep(3);
                            goto min_max_menu;

                        case 2:

                            max = maxValue(root);
                            printf("\nMaximum Element --> %d", max);
                            sleep(3);
                            goto min_max_menu;

                        case 3:

                            goto menu;

                        default :

                            printf("\nINVALID INPUT !");
                            sleep(3);
                            goto min_max_menu;
                    }

            case 6:

                printf("\nTHANK YOU !");
                sleep(2);
                exit(0);

            default :

                printf("\nINVALID INPUT !");
                sleep(3);
                goto menu;
        }
}

nd * insert(nd *root, int value)
{
    if (root == NULL)
    {
        nd *newnode = (nd *)malloc(sizeof(nd));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        root = newnode;
        
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        printf("\nDUPLICATE KEYS NOT ALLOWED !");
    }

    return root;
}

nd * removeData(nd *root, int value)
{
    nd *temp = NULL;

    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = removeData(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = removeData(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = inOrder_predecessor(root->left);
        root->data = temp->data;
        root->left = removeData(root->left, temp->data);
    }

    return root;
}

nd * inOrder_predecessor(nd *root)
{
    while (root->right!=NULL)
    {
        root = root->right;
    }

    return root;
}

void preOrder(nd *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d\t", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(nd *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d\t", root->data);
    inOrder(root->right);
}

void postOrder(nd *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t", root->data);
}

int minValue(nd *root)
{
    if (root == NULL)
    {
        printf("\nTREE IS EMPTY !");
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

int maxValue(nd *root)
{
    if (root == NULL)
    {
        printf("\nTREE IS EMPTY !");
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

void count_leafNodes(nd *root, int *ln)
{
    if (root!=NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            (*ln)++;
        }

        count_leafNodes(root->left, ln);
        count_leafNodes(root->right, ln);
    }
}

void count_leftChild(nd *root, int *lc)
{
    if (root!=NULL)
    {
        if (root->left != NULL && root->right == NULL)
        {
            (*lc)++;
        }

        count_leftChild(root->left, lc);
        count_leftChild(root->right, lc);
    }
}

void count_rightChild(nd *root, int *rc)
{
    if (root!=NULL)
    {
        if (root->left == NULL && root->right != NULL)
        {
            (*rc)++;
        }

        count_rightChild(root->left, rc);
        count_rightChild(root->right, rc);
    }
}

void count_bothChild(nd *root, int *bc)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            (*bc)++;
        }

        count_bothChild(root->left, bc);
        count_bothChild(root->right, bc);
    }
}