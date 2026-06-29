class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int st = 0;
        int end = r * c - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            int element = matrix[mid / c][mid % c];
            if(element == target){
                return true;
            }
            if(element < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }
};