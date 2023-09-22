//  Doubly Linked List ---->

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to display the doubly linked list in forward direction
void displayForward(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the doubly linked list in reverse direction
void displayBackward(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("NULL <- ");
    while (current != NULL) {
        printf("%d <- ", current->data);
        current = current->prev;
    }
    printf("HEAD\n");
}

int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 2);

    printf("Doubly linked list in forward direction:\n");
    displayForward(head);

    printf("Doubly linked list in reverse direction:\n");
    displayBackward(head);

    return 0;
}
