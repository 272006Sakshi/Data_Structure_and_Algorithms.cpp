class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long res = 0;
        long cnt_zero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                cnt_zero++;
                res+=cnt_zero;
            }
            else{
                cnt_zero = 0;
            }
            
        }
        return res;



    }
};
