#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode *head1 = NULL;
    struct ListNode *tail1 = NULL;
    struct ListNode *temp = head;

    while (temp != NULL) {
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = temp->val;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
        temp = temp->next;
    }
    struct ListNode *prev = NULL;
    struct ListNode *curr = head1;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head1 = prev;
    struct ListNode *temp1 = head;
    struct ListNode *temp2 = head1;
    bool result = true;
    
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val != temp2->val) {
            result = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (head1 != NULL) {
        struct ListNode *toDelete = head1;
        head1 = head1->next;
        free(toDelete);
    }

    return result;
}
