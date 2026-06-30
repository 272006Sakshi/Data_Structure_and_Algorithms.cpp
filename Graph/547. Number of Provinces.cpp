class Solution {
public:
// T.C: O(N^2)
    int n; 
    void dfs(vector<bool> &visited, int node, vector<vector<int>> &isConnected){
        visited[node] = true;
        for(int v=0; v<n; v++){
            if(!visited[v] && isConnected[node][v]==1){
                dfs(visited, v, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                res++;
                dfs(visited, i, isConnected);
            }
        }
        return res;
    }
};
