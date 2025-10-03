class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // brute force 
        // T.C : O(k*(m+n)), S.C : O(k)   k = mn (worst case)
        
        // vector<pair<int, int>> zeros;

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         if(matrix[i][j] == 0){
        //             zeros.emplace_back(i, j);
        //         }
        //     }
        // }

        // for(auto &it : zeros){
        //     int r = it.first, c = it.second;

        //     for(int j = 0; j<m; j++) matrix[r][j] = 0;
        //     for(int i = 0; i<n; i++) matrix[i][c] = 0;
        // }
        

        // better Approach : extra space
        vector<bool> row(n, false), col(m, false);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
