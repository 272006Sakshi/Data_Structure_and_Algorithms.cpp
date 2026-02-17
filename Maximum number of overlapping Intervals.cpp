class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> st(n);
        vector<int> end(n);
        for(int i = 0; i<n; i++){
            st[i] = arr[i][0];
            end[i] = arr[i][1];
        }
        sort(st.begin(), st.end());
        sort(end.begin(), end.end());
        
        int i = 0;
        int j = 0;
        int overlap = 0;
        int res = 0;
        
        while(i<n && j<n){
            if(st[i]<=end[j]){
                overlap++;
                res = max(res, overlap);
                i++;
            }
            else{
                overlap--;
                j++;
            }
        }
        return res;
    }
};
