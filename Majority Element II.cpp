class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> res;
        unordered_map<int, int> count;
        
        for(int i  = 0; i<n; i++){
            count[arr[i]]++;
        }
        for(auto &num : count){
            if(num.second > n/3) res.push_back(num.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
