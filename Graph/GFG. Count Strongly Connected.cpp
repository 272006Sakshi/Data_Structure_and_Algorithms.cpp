class Solution {
  public:
// T.C: O(V+E)
// S.C: O(V+E)
    void dfsTopo(int u, vector<vector<int>> &edges,
                 vector<bool> &visited, stack<int> &st) {
        visited[u] = true;
        for(int v : edges[u]) {
            if(!visited[v]) {
                dfsTopo(v, edges, visited, st);
            }
        }
        st.push(u);
    }

    void dfsTrav(int node, vector<vector<int>> &revEdges,
                 vector<bool> &visited) {

        visited[node] = true;
        for(int v : revEdges[node]) {
            if(!visited[v]) {
                dfsTrav(v, revEdges, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {

        // 1. DFS + Topological ordering
        stack<int> st;
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfsTopo(i, edges, visited, st);
            }
        }

        // 2. Reverse the graph
        vector<vector<int>> revEdges(V);

        for(int u = 0; u < V; u++) {
            for(int v : edges[u]) {
                revEdges[v].push_back(u);
            }
        }

        // 3. DFS according to stack order
        visited = vector<bool>(V, false);

        int sccCnt = 0;

        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(!visited[node]) {
                dfsTrav(node, revEdges, visited);
                sccCnt++;
            }
        }

        return sccCnt;
    }
};
