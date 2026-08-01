class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        if(i == j)
            return nums[i];
        int takeLeft = nums[i] - solve(nums, i + 1, j);
        int takeRight = nums[j] - solve(nums, i, j - 1);
        return max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};