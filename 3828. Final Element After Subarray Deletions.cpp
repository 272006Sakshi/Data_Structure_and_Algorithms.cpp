class Solution {
public:
    int finalElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(nums[0], nums[nums.size()-1]);
        
    }
};
