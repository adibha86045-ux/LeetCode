class Solution {
private:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        int ans = max(left,right)+ 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int dia1 = diameterOfBinaryTree(root -> left);
        int dia2 = diameterOfBinaryTree(root -> right);
        int dia3 = maxDepth(root -> left) + maxDepth(root -> right);
        int ans = max(dia1, max(dia2,dia3));
        return ans;
    }
};