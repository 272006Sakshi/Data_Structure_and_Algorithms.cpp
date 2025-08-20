class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        // approach: 2D array(matrix) ko 1D me change kar ke linear search ka use karke 
        // target find karenge if target is present then true return kar denge.
        
        // convert matrix into 1D array then apply kadane's algo 
        for(int start = 0; start<m; start++){
            vector<int> vec(n, 0);
            for(int end = start; end<m; end++){
                for(int i = 0; i<n; i++){
                    vec[i]=mat[i][end];
                }
                
                for(int j=0; j<n; j++){
                    if(vec[j] == x){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};
