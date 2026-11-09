class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prev = dummy;

        while(prev -> next != NULL && prev -> next -> next != NULL){

            ListNode* first = prev -> next;
            ListNode* second = prev -> next -> next;

            first -> next = second -> next;
            second -> next = first;
            prev -> next = second;

            prev = first;
        }

        return dummy -> next;
    }
};