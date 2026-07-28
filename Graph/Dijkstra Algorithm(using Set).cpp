class Solution {
  public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V); // adj[node] = {{neighbour, weight}, ...}
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // Since the graph is undirected
        }
        //min heap
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        
        // set
        set<pair<int, int>> st;
        st.insert({0, src});
        
        // Step 4: Dijkstra's algorithm
        while (!st.empty()) {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto &ngb : adj[node]) {
                int adjNode = ngb.first;
                int weight = ngb.second;
                
                // If a shorter path is found
                if (d + weight < dist[adjNode]) {
                    if(dist[adjNode]!=INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + weight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
