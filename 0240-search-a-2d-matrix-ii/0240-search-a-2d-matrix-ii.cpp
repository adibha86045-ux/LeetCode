class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int RI = 0;
        int CI = c - 1;
        while (RI < r && CI >= 0) {
            int element = matrix[RI][CI];
            if (element == target) {
                return true;
            }
            if (element < target) {
                RI++;
            }
            else {
                CI--;
            }
        }
        return false;
    }
};