#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty !\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d \n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty !\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == NULL) {
        printf("Deleted %d \n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void deleteMiddle(int pos) {
    if (head == NULL) {
        printf("List is empty !\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position !\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted %d \n", temp->data);
    free(temp);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, pos;

    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);

    while (1) {
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Middle\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteBeginning();
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice !\n");
        }
    }
    return 0;
}

