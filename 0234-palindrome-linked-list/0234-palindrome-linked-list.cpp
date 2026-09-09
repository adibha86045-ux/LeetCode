class Solution {
private:
ListNode* getmiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
ListNode* reverse(ListNode* & head){
    ListNode* current = head;
    ListNode* previous = NULL;
    ListNode* forward = NULL;
    while(current != NULL){
        forward = current -> next;
        current -> next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}
public:
    bool isPalindrome(ListNode* head) {
       if(head -> next == NULL){
            return true;
       }
       ListNode* middle = getmiddle(head);
       ListNode* temp = middle -> next;
       middle -> next = reverse(temp);
       ListNode* head1 = head;
       ListNode* head2 = middle -> next;
       while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
       }
       return true;
    }
};