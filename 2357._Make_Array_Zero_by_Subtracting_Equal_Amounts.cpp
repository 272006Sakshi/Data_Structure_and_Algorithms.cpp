class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
        if (nums[i] > 0 && (i == 0 || nums[i] != nums[i-1])) {
            ++cnt;
        }
    }
    return cnt;


    }
};
