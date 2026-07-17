class Solution {
public:
    //  // DFS
    // bool checkDFS(int currNode, vector<vector<int>>& graph, vector<int> &colorVec, int currColor){
    //     //curr node ko color karenge
    //     colorVec[currNode] = currColor;
    //     // neighbors ko check karenge
    //     for(auto &v:graph[currNode]){
    //         if(colorVec[v]==colorVec[currNode]){
    //             return false;
    //         }
    //         if(colorVec[v]==-1){
    //             int colorV = 1 - currColor;
    //             if(checkDFS(v, graph, colorVec, colorV)==false){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    // BFS
    bool checkBFS(int currNode, vector<vector<int>>& graph, vector<int> &colorVec, int currColor){
        queue<int> que;
        que.push(currNode);
        //color curr node
        colorVec[currNode] = currColor;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto &v: graph[u]){
                if(colorVec[v]==colorVec[u]){
                    return false;
                }
                if(colorVec[v]==-1){
                    colorVec[v] = 1-colorVec[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorVec(n, -1);

        for(int i=0;i<n;i++){
            if(colorVec[i]==-1){
                if(checkBFS(i, graph, colorVec, 1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
