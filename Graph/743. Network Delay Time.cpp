class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<int> res(n+1, INT_MAX);
        res[k]=0;
        minheap.push({0, k});
        while(!minheap.empty()){
            int dist = minheap.top().first;
            int node = minheap.top().second;
            minheap.pop();

            for(auto &it:adj[node]){ 
                int adjNode = it.first;
                int wt = it.second;

                if(res[adjNode]>dist+wt){
                    res[adjNode] = dist+wt;
                    minheap.push({res[adjNode], adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            ans = max(ans, res[i]);
        }
        return ans==INT_MAX?-1:ans;

    }
};
