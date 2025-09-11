class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int res = 0;
        for(int i = 0; i<n; i++){
            res = max(res, abs(mices[i]-holes[i]));
        }
        return res;
        
    }
};
