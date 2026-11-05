#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, element;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(element);
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
