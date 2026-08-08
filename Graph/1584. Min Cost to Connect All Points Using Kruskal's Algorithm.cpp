class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x){
          return x;
        }
        return parent[x] = find(parent[x]);
    }
  
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
      
        if(x_parent == y_parent) return;
      
        if(rank[x_parent]>rank[y_parent]){
          parent[y_parent] = x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
          parent[x_parent] = y_parent;
        }
        else{
          parent[y_parent] = x_parent;
          rank[x_parent]++;
        }
      
    }
    int kruskalAlgo(vector<vector<int>> &arr) {
        // code here
        // graph
        int mincost = 0;
        for(auto &it:arr){
            int u=it[0];
            int v=it[1];
            int cost = it[2];

            int u_parent = find(u);
            int v_parent = find(v);
            if(u_parent != v_parent){
                Union(u, v);
                mincost+=cost;
            }
        }
        return mincost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xi = points[i][0];
                int yi = points[i][1];

                int xj = points[j][0];
                int yj = points[j][1];
                int dist = abs(xi-xj) + abs(yi-yj);

                arr.push_back({i, j, dist});
            }
        }
        auto sortedArr = [&](vector<int> &arr1, vector<int> &arr2){
            return arr1[2]<arr2[2];
        };
        sort(arr.begin(), arr.end(), sortedArr);
        return kruskalAlgo(arr);
    }
};
