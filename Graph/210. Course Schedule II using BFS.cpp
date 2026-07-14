class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        queue<int> que;
        vector<int> res;
        int visit=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                visit++;
                que.push(i);
                res.push_back(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    visit++;
                    que.push(v);
                    res.push_back(v);
                }
            }
        }
        if(visit==n) return res;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &arr: prerequisites){
            int a = arr[0];
            int b = arr[1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        return topoSort(adj, numCourses, indegree);
    }
};
