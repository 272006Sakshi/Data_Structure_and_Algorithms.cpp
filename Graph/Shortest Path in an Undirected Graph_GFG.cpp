class Solution {
  public:
  // dijkstra Algo
    vector<int> dijkstra(int src, int V, vector<vector<pair<int,int>>> &adj){

    vector<int> dist(V + 1, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){

        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto &[ngb, wt] : adj[node]){

            if(dist[ngb] > d + wt){

                dist[ngb] = d + wt;
                pq.push({dist[ngb], ngb});
            }
        }
    }

    return dist;
}
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
        // Adjacency list
        vector<vector<pair<int,int>>> adj(V + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  
        }

        for(int i = 1; i <= V; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        
        vector<int> srcDist = dijkstra(src, V, adj);
        if(srcDist[dest]==INT_MAX){
            return {-1};
        }
        vector<int> destDist = dijkstra(dest, V, adj);
        vector<int> ans;

        int curr = src;

        ans.push_back(curr);

        while(curr != dest){

            for(auto &[ngb,wt] : adj[curr]){

                if(srcDist[curr] + wt + destDist[ngb] == srcDist[dest]){

                    curr = ngb;
                    ans.push_back(curr);
                    break;
                }
            }
        }

        return ans;
           
    }
};
