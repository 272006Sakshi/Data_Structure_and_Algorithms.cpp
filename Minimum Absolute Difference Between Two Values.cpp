class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        
        int i = 0;
        while(i<n){
            for(int j = 1;j<n;j++){
                if((nums[i]==1 && nums[j]==2) || (nums[i]==2 && nums[j]==1)){
                    res = min(res, abs(i-j));
                }
                
            }
            i++;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};
