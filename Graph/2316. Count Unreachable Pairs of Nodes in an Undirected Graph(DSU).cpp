class Solution {
public: 
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par){
            return;
        }
        else if(rank[x_par]>rank[y_par]){
            parent[y_par] = x_par;
        }
        else if(rank[x_par]<rank[y_par]){
            parent[x_par] = y_par;
        }
        else{
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &arr:edges){
            int u=arr[0];
            int v = arr[1];
            Union(u, v);
        }

        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int parent = find(i);
            mp[parent]++;
        }

        long res = 0;
        long remSize = n;
        for(auto &it: mp){
            long size = it.second;
            res+=(size) * (remSize-size);
            remSize-=size;
        }
        return res;
    }
};
