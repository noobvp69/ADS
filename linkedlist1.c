#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertEnd(struct Node** head, int data);
void insertMid(struct Node** head, int data, int position);
void deleteEnd(struct Node** head);
void deleteMid(struct Node** head, int position);
void deleteNode(struct Node** head, int data);
int search(struct Node* head, int key);
void display(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at mid\n");
        printf("3. Delete from end\n");
        printf("4. Delete from mid\n");
        printf("5. Delete by value\n");
        printf("6. Search\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at mid: ");
                scanf("%d", &data);
                printf("Enter the position to insert the data: ");
                scanf("%d", &position);
                insertMid(&head, data, position);
                break;
            case 3:
                deleteEnd(&head);
                break;
            case 4:
                printf("Enter the position to delete the data: ");
                scanf("%d", &position);
                deleteMid(&head, position);
                break;
            case 5:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 6:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                position = search(head, data);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at end.\n");
}

// Function to insert a node at a specific position
void insertMid(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) { // Insert at beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node from the end
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) { // Only one node in the list
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Node deleted from end.\n");
}

// Function to delete a node at a specific position
void deleteMid(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    
    if (position == 1) { // Delete head node
        *head = temp->next;
        free(temp);
    } else {
        struct Node* prev;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("Node deleted from position %d.\n", position);
}

// Function to delete a node by its value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) { // If head node itself holds the key to be deleted
        *head = temp->next; // Change head
        free(temp);          // Free old head
        printf("Node with data %d deleted.\n", data);
        return;
    }

    while (temp != NULL && temp->data != data) { // Search for the key to be deleted
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) { // If key was not present in linked list
        printf("Node with data %d not found.\n", data);
        return;
    }

    prev->next = temp->next; // Unlink the node from linked list
    free(temp); // Free memory
    printf("Node with data %d deleted.\n", data);
}

// Function to search for an element in the list
int search(struct Node* head, int key) {
    int position = 1;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1; // Element not found
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

