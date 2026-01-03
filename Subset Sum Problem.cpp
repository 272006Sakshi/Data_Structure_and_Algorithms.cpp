// Platform: GFG
// 0/1 knapsack problem pattern--> tabulation 
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
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
};
