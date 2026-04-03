class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        vector<int> res;
        map<int, vector<int>> mp;
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mp){
            for(int &val:it.second){
                res.push_back(val);
            }
        }
        return res;
    }
};
