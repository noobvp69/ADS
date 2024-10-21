#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top pointer of the stack
struct Node* top = NULL;

// Function to insert (push) an element into the stack
void insert(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Inserted %d\n", element);
}

// Function to delete (pop) an element from the stack
void delete() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("Deleted %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Function to display the elements of the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function to handle stack operations
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert (Push)\n2. Delete (Pop)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}

