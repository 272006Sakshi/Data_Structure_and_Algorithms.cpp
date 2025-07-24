class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //sort first
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<n;i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        
        return nums[n-1];
    }
};
