class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maxValue = nums[0];
            for (int j = 0; j <= i; j++) {
                maxValue = max(maxValue, nums[j]);
            }
            int minValue = nums[i];
            for (int j = i; j < n; j++) {
                minValue = min(minValue, nums[j]);
            }
            int score = maxValue - minValue;
            if (score <= k) {
                return i;
            }
        }
        return -1;
    }
};