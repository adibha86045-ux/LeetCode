class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* current = head;
        while(current != NULL){
           if((current -> next != NULL) && current -> val == current -> next -> val){
            ListNode* next_next_node = current -> next -> next;
            ListNode* nodetodelete = current -> next;
            delete(nodetodelete);
            current -> next = next_next_node;
           } 
           else{
            current = current -> next;
           }
        }
        return head;
    }
};