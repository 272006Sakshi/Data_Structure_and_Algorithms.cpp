class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int cnt = 0;
        for(;j<nums.size()-1; j++){
            if((nums[i]<nums[j] && nums[j]>nums[j+1]) || (nums[i]>nums[j] && nums[j]<nums[j+1])){
                cnt++;
                i = j;
            }
        }
        return cnt;
    }
};
