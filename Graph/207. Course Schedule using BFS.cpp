class Solution {
public:
    bool KahnsAlgo(unordered_map<int, vector<int>> &adj, vector<int> &indegree, int n){
        queue<int> que;
        int visit = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                visit++;
                que.push(i);
            }
        }    
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    visit++;
                    que.push(v);
                }
            }
        }

        if(visit==n) return true;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto& arr:prerequisites){
            int a = arr[0];
            int b = arr[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return KahnsAlgo(adj, indegree, numCourses);
    }
};
