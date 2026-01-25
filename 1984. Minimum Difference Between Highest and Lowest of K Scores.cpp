class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = nums[k-1] - nums[0];
        for(int i = 0; i+k<=n; i++){
            diff = min(diff, nums[i+k-1]-nums[i]);
        }
        return diff;

    }
};
