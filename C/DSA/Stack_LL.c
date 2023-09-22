//  Stack Using Linked List ---->

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Define a structure for the stack
struct Stack {
    Node* top;
};

typedef struct Stack Stack;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack without popping it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    printf("Top element: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    display(stack);

    return 0;
}