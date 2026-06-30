class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){ 
            adj[e[0]].push_back(e[1]); 
        }
        vector<int> indegree(V, 0);
        queue<int> que;
        
        //1. saare ka indegree find karenge
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        //2. agar indegree 0 hai to usko queue me push karenge
        for(int i=0;i<V; i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        // 3. BFS 
        vector<int> ans;
        while(!que.empty()){
            int u = que.front();
            ans.push_back(u);
            que.pop();
            
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        return ans;
    }
};
