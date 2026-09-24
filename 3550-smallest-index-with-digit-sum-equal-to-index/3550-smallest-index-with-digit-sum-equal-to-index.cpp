class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            int digit;
            int x = nums[i];
            while(x != 0){
                digit = x % 10;
                sum = digit + sum;
                x = x/10;
            }
            if(i == sum){
                return i;
            }
        }
    return -1;
    }
};