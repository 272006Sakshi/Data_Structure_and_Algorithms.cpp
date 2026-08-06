class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
      // t.c: o(n^3)
        int n = dist.size();
        // set diagonal=0
        for(int d=0;d<n;d++) dist[d][d]=0;
        
        // via each vertev
        for(int via=0;via<n; via++){
            
            // update distance
            for(int i=0; i<n;i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] < 1e8 && dist[via][j] < 1e8){
                        int newdist = dist[i][via]+dist[via][j];
                        if(newdist<dist[i][j]) dist[i][j] = newdist;
                    }
                }
            }
        }
        
    }
};
