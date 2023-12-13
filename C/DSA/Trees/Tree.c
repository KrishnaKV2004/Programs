#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} nd;

nd *insert(nd *, int);

void inorder(nd *);
void preorder(nd *);
void postorder(nd *);

int main()
{
    int value;
    char choice;
    char var_choice;
    nd *root = NULL;

    while (1)
    {
        system("cls");
        printf("\n#---- Binary Search Tree ----#\n\n");
        printf("Operations -->\n\n");
        printf("[I] To Insert Data In Tree\n");
        printf("[D] To Delete Data In Tree\n");
        printf("[V] To View Data In Tree\n");
        printf("[E] To Exit\n");
        printf("\nEnter Choice --> ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'I':
        case 'i':

            printf("\nEnter Value To Insert --> ");
            scanf("%d",&value);

            root = insert(root, value);
            break;

        case 'V':
        case 'v':

            system("cls");
            printf("\nChoose Operation --> \n\n");
            printf("[I] For Inorder Traversal\n");
            printf("[R] For Preorder Traversal\n");
            printf("[P] For Postorder Traversal\n");
            printf("[E] To Exit\n");
            printf("\nEnter Choice --> ");
            scanf(" %c", &var_choice);

            switch (var_choice)
            {
            case 'I':
            case 'i':

                if (root == NULL)
                {
                    printf("\nTree Is Empty !\n");
                    sleep(2);
                }

                printf("\nIn Order Traversal -->\n\n");
                inorder(root);
                sleep(10);
                break;

            case 'R':
            case 'r':

                if (root == NULL)
                {
                    printf("\nTree Is Empty !\n");
                    sleep(2);
                }

                printf("Pre Order Traversal -->\n\n");
                preorder(root);
                sleep(10);
                break;

            case 'P':
            case 'p':

                if (root == NULL)
                {
                    printf("\nTree Is Empty !\n");
                    sleep(2);
                }

                printf("\nPost Order Traversal -->\n\n");
                postorder(root);
                sleep(10);
                break;

            case 'E':
            case 'e':

                printf("\nThank You !");
                sleep(3);
                exit(0);
                break;

            default:

                printf("\nInvalid Input !\n");
                sleep(3);
                break;

        case 'E':
        case 'e':

            printf("\nThank You !");
            sleep(3);
            exit(0);

        default:

            printf("\nInvalid Input !\n");
            sleep(3);
            break;
        }
    }

    return 0;
}

nd *insert(nd *root, int value)
{
    nd *newnode = (nd *)malloc(sizeof(nd));

    if (root == NULL)
    {
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(nd *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(nd *root)
{
    
}

void postorder(nd *root)
{

}