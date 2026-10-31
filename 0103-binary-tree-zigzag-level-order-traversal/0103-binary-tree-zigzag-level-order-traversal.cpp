class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue <TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()){
           
           int size = q.size() ;
           vector <int> ans(size);

           for(int i = 0; i < size; i++){
              
               TreeNode* frontnode = q.front();
               q.pop();

               int index = left_to_right ? i : size - i - 1;
               ans[index] = frontnode -> val;

               if(frontnode -> left){
                  q.push(frontnode -> left);
               }
               if(frontnode -> right){
                  q.push(frontnode -> right);
               }
            }

            left_to_right = !left_to_right;

            result.push_back(ans);
        }
        return result;
    }
};