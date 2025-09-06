class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;

        int currSum = 0, l = 0;
        for(int r = 0; r<n; r++){
            currSum += nums[r];
            while(currSum>=target){
                if(r-l+1 <minLen){
                    minLen = min(minLen, r-l+1);

                }
                currSum -= nums[l];
                l++;
            }

        }
        return minLen != INT_MAX ? minLen : 0;
    }
};
