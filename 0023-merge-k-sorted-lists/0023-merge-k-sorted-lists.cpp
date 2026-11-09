class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       vector<int> answer;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while(temp != NULL) {
                int ans = temp->val;
                answer.push_back(ans);
                temp = temp->next;
            }
        }

        sort(answer.begin(), answer.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for(int i = 0; i < answer.size(); i++) {
            curr->next = new ListNode(answer[i]);
            curr = curr->next;
        }

        return dummy->next;
    }
};