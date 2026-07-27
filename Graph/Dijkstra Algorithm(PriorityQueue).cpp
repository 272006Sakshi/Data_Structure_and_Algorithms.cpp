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
        
        // Step 3: Min-heap priority queue: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        // Step 4: Dijkstra's algorithm
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                
                // If a shorter path is found
                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
