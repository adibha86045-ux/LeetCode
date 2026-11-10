class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* temp = dummy;

        while(temp -> next != NULL && temp -> next -> next != NULL) {

            if(temp -> next -> val == temp -> next -> next -> val) {

                int ans = temp -> next -> val;

                while(temp -> next != NULL && temp -> next -> val == ans) {
                    temp -> next = temp -> next -> next;
                }
            }
            else {
                temp = temp -> next;
            }
        }

        return dummy -> next;
    }
};