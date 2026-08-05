class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // T.C: O(E*V)
        vector<int> distArr(V, 10e7);
        distArr[src] = 0;
        for(int i=0; i<=V-1; i++){
            for(auto &edge:edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(distArr[u]!=10e7 && distArr[u]+wt<distArr[v]){
                    distArr[v] = distArr[u]+wt;
                }
            }
        }
        // one more relax for detect -ve weight
        for(int i=0; i<=V-1; i++){
            for(auto &edge:edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(distArr[u]!=10e7 && distArr[u]+wt<distArr[v]){
                    return {-1};
                }
            }
        }
        return distArr;
    }
};
