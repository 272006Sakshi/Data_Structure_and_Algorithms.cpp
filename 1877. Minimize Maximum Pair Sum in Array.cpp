class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n-1;
        int maxi = 0;
        while(left<right){
            maxi = max(maxi, nums[left]+nums[right]);
            left++;
            right--;
        }
        return maxi;
    }
};
