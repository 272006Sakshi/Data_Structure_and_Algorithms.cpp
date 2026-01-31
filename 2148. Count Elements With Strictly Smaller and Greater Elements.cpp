class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int i = 1;
        while(i<n-1){
            if(nums[i]>=nums[i-1] && nums[i]<=nums[i+1]){
                if(nums[i]!=nums[0] && nums[i]!=nums[n-1]){
                   cnt++;
                }   
            }
            i++;
        }
        return cnt;

    }
};
