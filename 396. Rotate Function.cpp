class Solution {
public:
// T.C:O(n)
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int sum=0;
        int fun = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fun += i*nums[i];
        }
        ans = fun;
        for(int i=1;i<n;i++){
            fun+=sum - n*nums[n-i];
            ans = max(ans, fun);
        }
        return ans;
    }
};
