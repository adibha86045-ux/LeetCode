class Solution {
private:
    ListNode* reverse(ListNode* & head){
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* agla = NULL;
        while(current != NULL){
            agla = current -> next;
            current -> next = prev;
            prev = current;
            current = agla;
        }
        return prev;
    }

    void inserattail(ListNode* &head,ListNode* &tail,int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }

    ListNode*add(ListNode* first,ListNode* second){
    int carry = 0;
    ListNode* anshead = NULL;
    ListNode* anstail = NULL;
    while(first != NULL || second != NULL){
        int val1 = 0;
        if(first != NULL){
            val1 = first -> val;
        }
        int val2 = 0;
        if(second != NULL){
            val2 = second -> val;
        }
        int sum = carry + val1+ val2;
        int digit = sum % 10;
        inserattail(anshead,anstail,digit);
        carry = sum / 10;
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
    } 
        if(carry != 0) {
            inserattail(anshead, anstail, carry);
        }
    return anshead;
}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return add(l1, l2);
}
};