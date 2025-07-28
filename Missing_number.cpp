class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i<nums.size();i++){
            N += i - nums[i];
        }
        return N;
    }
};
