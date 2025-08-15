class Solution {
  public:
    
    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;
        // convert matrix into 1D array then apply kadane's algo 
        for(int start = 0; start<m; start++){
            vector<int> vec(n, 0);
            for(int end = start; end<m; end++){
                for(int i = 0; i<n; i++){
                    vec[i]+=mat[i][end];
                }
                
                // kadane's algorithm 
                int maxi = INT_MIN, sum = 0;
                for(int i = 0; i<n; i++){
                    sum+=vec[i];
                    maxi = max(maxi, sum);
                    if(sum<0) sum = 0;
                }
                maxSum = max(maxi, maxSum);
            }
        }
        return maxSum;
    }
};
