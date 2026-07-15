class Solution {
public:
    // DFS
    bool isCycle;

    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recursion, stack<int> &st){
        visited[u]=true;
        recursion[u]=true;
        for(int &v:adj[u]){
            if(recursion[v]==true){
                isCycle = true;
                return;
            }
            if(!visited[v]){
                DFS(adj, v, visited, recursion, st);
            }
        }
        st.push(u);
        recursion[u]=false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &arr:prerequisites){
            int a = arr[0];
            int b = arr[1];
            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recursion(numCourses, false);
        stack<int> st;
        isCycle=false;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                DFS(adj, i, visited, recursion, st);
            }
        }
        //cycle present--> means we cannot complete course, then return empty array
        if(isCycle==true){
            return {};
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
