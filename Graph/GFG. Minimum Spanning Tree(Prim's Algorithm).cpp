class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

// T.C: O(ElogV)
        // code here
        // graph
        vector<vector<pair<int, int>>> adj(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        int sum = 0;
        // visited array
        vector<bool> visited(V, false);
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            if(visited[node]==true){
                continue;
            }
            visited[node] = true;
            sum+=wt;
            
            for(auto &it:adj[node]){
                int ngb = it.first;
                int ngb_wt = it.second;
                
                if(visited[ngb]==false){
                    pq.push({ngb_wt, ngb});
                }
            }
            
        }
        return sum;
        
    }
};
