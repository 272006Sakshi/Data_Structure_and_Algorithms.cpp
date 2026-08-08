class Solution {
  public:
  // DSU
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
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        parent.resize(V);
        rank.assign(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Sort edges by weight
        auto sortedArr = [&](vector<int> &arr1, vector<int> &arr2){
            return arr1[2]<arr2[2];
        };
        sort(edges.begin(), edges.end(), sortedArr);

        int sum = 0;
        int edgesUsed = 0;

        // Kruskal Algo
        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (find(u) != find(v)) {
                Union(u, v);
                sum += wt;
                edgesUsed++;
            }
            if (edgesUsed == V - 1)
                break;
        }

        return sum;
    }
};
