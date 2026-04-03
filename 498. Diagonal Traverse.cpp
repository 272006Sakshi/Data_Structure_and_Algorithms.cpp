class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        // int m = matrix.size(), n = matrix[0].size();
        // vector<int> result(m*n);
        // int row = 0, col = 0;

        // for (int i = 0; i < m * n; i++) {
        //     result[i] = matrix[row][col];

        //     if ((row + col) % 2 == 0) {
        //         if (col == n - 1) row++;
        //         else if (row == 0) col++;
        //         else { row--; col++; }
        //     } else {
        //         if (row == m - 1) col++;
        //         else if (col == 0) row++;
        //         else { row++; col--; }
        //     }
        // }
        // return result;


        // Approach: 2  
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        map<int, vector<int>> mp;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        bool flag = true;
        for(auto &it:mp){
            if(flag){
                reverse(it.second.begin(), it.second.end());
            }
            for(int &val:it.second){
                res.push_back(val);
            }
            flag = !flag;
        }
        return res;
    }
};
