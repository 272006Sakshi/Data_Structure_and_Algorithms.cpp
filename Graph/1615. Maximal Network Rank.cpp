class Solution {
public:
// T.C: O(V^2)
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // adj list;
        unordered_map<int, unordered_set<int>> adj;
        for(auto &edge:roads){
            int u=edge[0];
            int v=edge[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxRank = 0;
        for(int i=0; i<n; i++){  //O(V)
            for(int j=i+1; j<n; j++){  //O(V)
                int rankI = adj[i].size();
                int rankJ = adj[j].size();
                int totalRank = rankI+rankJ;
                if(adj[i].find(j)!=adj[i].end()){  // O(1)
                    totalRank--;
                }
                maxRank = max(maxRank, totalRank);
            }
        }
        return maxRank;
    }
};
