class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int count = 0;
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;
        while (count < total) {
         for (int i = left; i <= right && count < total; i++) {
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for (int i = top; i <= bottom && count < total; i++) {
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            for (int i = right; i >= left && count < total; i--) {
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            for (int i = bottom; i >= top && count < total; i--) {
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};