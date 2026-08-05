class Solution {
public:

//T.C: O(V+E)
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n); 
        vector<int> indegree(n, 0); 

        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        vector<bool> bug(n, false);
        vector<int> res;
        queue<int> que;
        que.push(k);
        bug[k] = true;

        while(!que.empty()) {
            int node = que.front();
            que.pop();

            for(int &ngb : graph[node]) {
                indegree[ngb]--;
                if(bug[ngb]==false) {
                    que.push(ngb);
                    bug[ngb] = true;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(bug[i] && indegree[i] > 0) {
                vector<int> res1(n); 
                for(int i = 0; i < n; i++) {
                   res1[i] = i;
                }
                return res1;
            }

            if(!bug[i]) {
                res.push_back(i);
            }

        } 
        return res;
    }
};
