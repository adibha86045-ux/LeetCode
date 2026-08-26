class Solution {
public:
void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    ListNode* forward = curr -> next;
    reverse(head,forward,curr);
    curr -> next = prev;
}
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* current = head;
        reverse(head,current,prev);
        return head;
        // if(head == NULL || head -> next == NULL){
        //     return head;
        // }
        // ListNode* prev = NULL;
        // ListNode* current = head;
        // ListNode* forward = NULL;
        // while(current != NULL){
        //    forward = current -> next;
        //    current -> next = prev;
        //    prev = current;
        //    current = forward; 
        // }
        // return prev;
    }
};