class Solution {
public:
    // Subset Sum : DP: 0/1 knapsack pattern(Tabulation)
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> mat(n+1, vector<bool>(sum+1, false));
        // base case: sum = 0 is always possible: empty subset
        for(int i = 0; i<=n; ++i){
            mat[i][0] = true;
        }
        
        for(int i = 1; i<=n; ++i){
            for(int s = 1; s<sum+1; ++s){
                if(arr[i-1] <= s){
                    mat[i][s] = (mat[i-1][s]) || (mat[i-1][s - arr[i-1]]);
                    
                }
                else{
                    mat[i][s] = mat[i-1][s];
                }
            }
        }
        return mat[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        //array-> [1,5,11,5]: partition possible hoga jb array sum even hoga.

        int Tsum = 0;
        for(int i = 0; i<n; i++){
            Tsum+=nums[i];
        }
        // check sum even or not
        if(Tsum%2!=0)return false;
        // agar sum even hai to hume sum/2 agr mil jaye means partition possible hai 
        // hum subset sum ke through isko find kar lenge
        // Subset Sum: hume array aur sum value diya hota hai. agar koi subset present hai jiska sum== sum value then return True.
        return isSubsetSum(nums, Tsum/2);
    }
};
