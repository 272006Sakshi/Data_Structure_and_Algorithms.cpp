class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto& ele : mp){
            if(ele.second>1) res.push_back(ele.first);
        }
        
        return res;
    }
};
