/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
bool checkpalindrome(vector<int> array){
    int n = array.size();
    int st = 0;
    int end = n-1;
    while(st <= end){
        if(array[st] != array[end]){
            return 0;
        }
        st++;
        end--;
    }
    return 1;
}
public:
    bool isPalindrome(ListNode* head) {
        vector <int> array;
        ListNode* temp = head;
        while(temp != NULL){
            array.push_back(temp -> val);
            temp = temp -> next;
        } 
        return checkpalindrome(array);
    }
};