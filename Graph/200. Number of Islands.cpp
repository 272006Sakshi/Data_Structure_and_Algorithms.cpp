class Solution {
public:
    // T.C: O(m × n)
   // S.C: O(m × n)
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m){
            return;
        }
        if(grid[row][col]=='0'){
            return;
        }
        grid[row][col]='0';
        dfs(row, col+1, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row-1, col, grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs(i, j, grid);
                }

            }
        }
        return res;
    }
};
