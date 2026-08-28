class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(temp == NULL) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        for(int i = 0; i < k; i++) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        head->next = reverseKGroup(current, k);
        return prev;
    }
};