void merge (vector <int>& arr,int st,int end,int mid){
    vector <int> temp;
    int right=mid+1;
    int left=st;
    while (left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=end){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=st;i<=end;i++){
        arr[i]=temp[i-st];
    }
}
void mergesort(vector <int>& arr,int st,int end){
    if(st>=end)
    return;
    int mid=(st+end)/2;
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,end);
    merge (arr,st,end,mid);

}
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return nums;
    }
};