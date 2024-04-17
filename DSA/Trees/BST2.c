#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* insertNode(TreeNode* root, int value);
void countTotalNodes(TreeNode* root, int* totalCount);
void countLeafNodes(TreeNode* root, int* leafCount);
void countNodesWithLeft(TreeNode* root, int* leftCount);
void countNodesWithRight(TreeNode* root, int* rightCount);
void countNodesWithBoth(TreeNode* root, int* bothCount);
int countLeftNodes(TreeNode* root);
int countRightNodes(TreeNode* root);
int findMaxValue(TreeNode* root);
int findMinValue(TreeNode* root);
TreeNode* removeNode(TreeNode* root, int value);
TreeNode* findInorderPredecessor(TreeNode* root);
void preOrderTraversal(TreeNode* root);
void inOrderTraversal(TreeNode* root);
void postOrderTraversal(TreeNode* root);

int main() {
    TreeNode* root = NULL;
    int choice, value, option, totalCount, maxValue, minValue;

    while (1) {
        printf("1. Insert a value\n");
        printf("2. Count total number of nodes\n");
        printf("3. Count total leaf nodes\n");
        printf("4. Count nodes with only left child\n");
        printf("5. Count nodes with only right child\n");
        printf("6. Count nodes with both children\n");
        printf("7. Count nodes on the left side of the root\n");
        printf("8. Count nodes on the right side of the root\n");
        printf("9. Find the node with the highest value\n");
        printf("10. Find the node with the lowest value\n");
        printf("11. Remove a node\n");
        printf("12. Preorder Traversal\n");
        printf("13. Inorder Traversal\n");
        printf("14. Postorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                totalCount = 0;
                countTotalNodes(root, &totalCount);
                printf("Total number of nodes: %d\n", totalCount);
                break;
            case 3:
                totalCount = 0;
                countLeafNodes(root, &totalCount);
                printf("Total leaf nodes: %d\n", totalCount);
                break;
            case 4:
                totalCount = 0;
                countNodesWithLeft(root, &totalCount);
                printf("Nodes with only a left child: %d\n", totalCount);
                break;
            case 5:
                totalCount = 0;
                countNodesWithRight(root, &totalCount);
                printf("Nodes with only a right child: %d\n", totalCount);
                break;
            case 6:
                totalCount = 0;
                countNodesWithBoth(root, &totalCount);
                printf("Nodes with both children: %d\n", totalCount);
                break;
            case 7:
                totalCount = countLeftNodes(root);
                printf("Nodes on the left side of the root: %d\n", totalCount);
                break;
            case 8:
                totalCount = countRightNodes(root);
                printf("Nodes on the right side of the root: %d\n", totalCount);
                break;
            case 9:
                maxValue = findMaxValue(root);
                printf("Node with the highest value: %d\n", maxValue);
                break;
            case 10:
                minValue = findMinValue(root);
                printf("Node with the lowest value: %d\n", minValue);
                break;
            case 11:
                printf("Enter a value to remove: ");
                scanf("%d", &value);
                root = removeNode(root, value);
                break;
            case 12:
                printf("Preorder Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 13:
                printf("Inorder Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 14:
                printf("Postorder Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &option);
        if (option == 0) {
            break;
        }
    }

    return 0;
}

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        printf("Duplicate value.\n");
    }
    return root;
}

void countTotalNodes(TreeNode* root, int* totalCount) {
    if (root != NULL) {
        (*totalCount)++;
        countTotalNodes(root->left, totalCount);
        countTotalNodes(root->right, totalCount);
    }
}

void countLeafNodes(TreeNode* root, int* leafCount) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            (*leafCount)++;
        }
        countLeafNodes(root->left, leafCount);
        countLeafNodes(root->right, leafCount);
    }
}

void countNodesWithLeft(TreeNode* root, int* leftCount) {
    if (root != NULL) {
        if (root->left != NULL && root->right == NULL) {
            (*leftCount)++;
        }
        countNodesWithLeft(root->left, leftCount);
        countNodesWithLeft(root->right, leftCount);
    }
}

void countNodesWithRight(TreeNode* root, int* rightCount) {
    if (root != NULL) {
        if (root->left == NULL && root->right != NULL) {
            (*rightCount)++;
        }
        countNodesWithRight(root->left, rightCount);
        countNodesWithRight(root->right, rightCount);
    }
}

void countNodesWithBoth(TreeNode* root, int* bothCount) {
    if (root != NULL) {
        if (root->left != NULL && root->right != NULL) {
            (*bothCount)++;
        }
        countNodesWithBoth(root->left, bothCount);
        countNodesWithBoth(root->right, bothCount);
    }
}

int findMinValue(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->value;
}

TreeNode* removeNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findInorderPredecessor(root);
        root->value = temp->value;
        root->left = removeNode(root->left, temp->value);
    }
    return root;
}

TreeNode* findInorderPredecessor(TreeNode* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->value);
}