// DFS
    bool DFScycle(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recursion){
        visited[u]=true;
        recursion[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && DFScycle(adj, v, visited, recursion)){
                return true;
            }
            else if(recursion[v]==true){
                return true;
            }
        }
        recursion[u]= false;
        return false;
    }             
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> recursion(numCourses, false);
        for(auto &arr:prerequisites){
            int a = arr[0];
            int b = arr[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && DFScycle(adj, i, visited, recursion)){
                return false;
            }
        }
        return true;
    }
};
