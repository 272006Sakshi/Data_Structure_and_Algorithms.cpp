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
        int x_par = find(x);
        int y_par = find(y);

        if(x_par==y_par){
            return;
        }
        else if(rank[x_par]>rank[y_par]){
            parent[y_par] = x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        if(connections.size() < n-1) return -1;
        int component = n;
        for(auto &arr:connections){
            if(find(arr[0]) != find(arr[1])){
                Union(arr[0], arr[1]);
                component--;
            }
        }
        return component-1;
    }
};
