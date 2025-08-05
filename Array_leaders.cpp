class Solution {
    
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector <int> res;
        
        int maxi = arr[n-1];
        res.push_back(maxi);
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] < maxi){
                continue;
            }
            else{
                maxi = arr[i];
                res.push_back(maxi);
            }    
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
