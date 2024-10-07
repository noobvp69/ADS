#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is full\n");
        return;
    } else if (front == -1) { // First element to be inserted
        front = rear = 0;
        queue[rear] = value;
    } else if (rear == MAX - 1 && front != 0) { // Wrap around
        rear = 0;
        queue[rear] = value;
    } else { // Normal case
        rear++;
        queue[rear] = value;
    }
    printf("Inserted %d\n", value);
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1; // Optional: Clear the dequeued position

    if (front == rear) { // Queue is now empty
        front = rear = -1;
    } else if (front == MAX - 1) { // Wrap around
        front = 0;
    } else {
        front++;
    }

    printf("Deleted %d\n", data);
    return data;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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

