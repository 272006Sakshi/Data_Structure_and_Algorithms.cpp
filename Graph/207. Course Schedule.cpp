class Solution {
public:
    bool checkCycle(unordered_map<int, vector<int>> &adj, int courses, vector<int> &indegree){
        queue<int> q;
        int cnt = 0;
        for(int i=0;i<courses;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
                
            }
        }
        if(cnt==courses){
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &arr:prerequisites){
            int u = arr[0];
            int v = arr[1];

            adj[v].push_back(u);
            indegree[u]++;
        }
        return checkCycle(adj, numCourses, indegree);
    }
};
