class Solution {
public:
    int primsAlgo(int V, vector<vector<pair<int, int>>> &adj){
        int mincost = 0;
        vector<bool> visited(V, false);
        // minheap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        minheap.push({0, 0});
        while(!minheap.empty()){
            int cost = minheap.top().first;
            int coord = minheap.top().second;
            minheap.pop();

            if(visited[coord]==true) continue;
            visited[coord] = true;
            mincost+=cost;

            for(auto &it:adj[coord]){
                int ngb = it.first;
                int ngb_cost = it.second;
                if(visited[ngb]==false){
                    minheap.push({ngb_cost, ngb});
                }
            }
        }
        return mincost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int xi = points[i][0];
                int yi = points[i][1];
                
                int xj = points[j][0];
                int yj = points[j][1];
                int dist = abs(xi-xj) + abs(yi-yj);
                
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }
        return primsAlgo(n, graph);
    }
};
