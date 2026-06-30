bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        // Using BFS --> Kahn's Algorithm
    
        vector<int> indegree(V, 0);
        queue<int> que;
        int count=0;
  // fill indegree
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
 // indegree ==0 push in queue       
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
  // BFS      
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                }
                
            }
        }
  // check id count == V means, all nodes visited--> no cycle--> return false , else return true
        if(count ==V){
            return false;
        }
        else{
            return true;
        }
    }
};
