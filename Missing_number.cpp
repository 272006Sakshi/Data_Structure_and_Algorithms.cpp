class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    //Approach1: T.C: O(n), S.C: O(1)

        // int sum = n*(n+1)/2;
        // int totSum = 0;

        // for(int i = 0; i<n; i++){
        //    totSum+=nums[i];
        // }
        // int res = sum-totSum;
        // return res;

    //Approach1: T.C: O(n), S.C: O(1)
        int res = n;
        for(int i = 0; i<n; i++){
            res += i-nums[i];
        } 
        return res;    
    }
};
