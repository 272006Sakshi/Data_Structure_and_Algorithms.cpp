class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n==3)return nums[0]+nums[1]+nums[2];
        vector<int> arr(nums.begin()+1, nums.end());
        sort(begin(arr), end(arr));
        return nums[0]+arr[0]+arr[1];
    }
};
