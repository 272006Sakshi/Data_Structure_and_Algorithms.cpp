class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        k = k%m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currVal = j;
                int nextVal;
                if(i%2==0){
                    nextVal = (j+k)%m;
                }
                else{
                    nextVal = (j-k+m)%m;
                }
                if(mat[i][currVal]!=mat[i][nextVal]) return false;
            }
        }
        return true;
    }
};
