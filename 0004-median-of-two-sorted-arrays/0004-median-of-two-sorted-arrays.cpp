#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    double median(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> vec;
        vec.reserve(n + m); 
        vec.insert(vec.end(), nums1.begin(), nums1.end());
        vec.insert(vec.end(), nums2.begin(), nums2.end());
        sort(vec.begin(), vec.end());
        int total_size = n + m;
        if (total_size % 2 != 0) {
            return vec[total_size / 2];
        } else {
            return (vec[(total_size / 2) - 1] + vec[total_size / 2]) / 2.0;
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return median(nums1, nums2);
    }
};
