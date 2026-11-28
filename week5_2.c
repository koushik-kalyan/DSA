struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    while (curr != NULL) {
        if (curr->next != NULL && curr->val == curr->next->val) {
            int dupVal = curr->val;
            while (curr != NULL && curr->val == dupVal) {
                struct ListNode* toDelete = curr;
                curr = curr->next;
                free(toDelete);
            }
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}
