class Solution {
public:
    // T.C: O(N^2)
    // S.C: O(N)

    // approah I-> top-down

    // int helper(int n, vector<int> &dp){
    //     if(n==0 || n==1) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     int res = 0;
    //     // if i-> root node
    //     for(int i = 1; i<=n; i++){
    //         res+=helper(i-1, dp)*helper(n-i, dp);
    //     }
    //     return dp[n] = res;
    // }
   
   // approach - II: tabulation
    int bottom(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            for(int j = 1; j<=i; j++){
                dp[i] += dp[j-1]*dp[i-j]; // i-> number of nodes aur j-> root node
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        // return helper(n, dp);
        return bottom(n);
    }
};
