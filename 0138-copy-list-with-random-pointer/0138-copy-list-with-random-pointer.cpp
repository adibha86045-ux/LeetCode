class Solution {
private:
    void inserattail(Node* &head,Node* &tail,int data){
        Node* temp = new Node(data);
        if(head == NULL){
            tail = temp;
            head = temp;
        }
        else{
        tail -> next = temp;
        tail = temp;
        }
    }
public:
    Node* copyRandomList(Node* head) {
       
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp != NULL){
            inserattail(clonehead,clonetail,temp -> val);
            temp = temp -> next;
        }

        Node* originalnode = head;
        Node* clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL){
            Node* next = originalnode -> next;
            originalnode -> next = clonenode;
            originalnode = next;

            next = clonenode -> next;
            clonenode -> next = originalnode;
            clonenode = next;
        }

        Node* aise = head;
        while(aise != NULL){
            if(aise -> next != NULL){
                if(aise -> random != NULL){
                    aise -> next -> random = aise -> random -> next;
                }
                else{
                   aise -> next -> random = NULL;
                }
            }
            aise = aise -> next -> next;
        }

        originalnode = head;
        clonenode = clonehead;
        while(originalnode != NULL && clonenode != NULL){
            originalnode -> next = clonenode -> next;
            originalnode = originalnode -> next;

            if(originalnode != NULL){
                clonenode -> next = originalnode -> next;
            }
            clonenode = clonenode -> next;
        }
        return clonehead;
    }
};