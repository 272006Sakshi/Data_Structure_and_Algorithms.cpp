class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        // Step 1: make a map where the key = |arr[i]-x| and value = vector of elements having that difference.
        // Step 2: Since map keeps keys sorted, iterating over it automatically gives elements in increasing order of difference.
        // Step 3: Push elements into ans and then assign arr = ans.
        // map<int, vector<int>> mp;
        // for(int i=0; i<n; i++){
        //     mp[abs(arr[i]-x)].push_back(arr[i]);
        
        // }
        // vector<int> ans;
        // for(auto it:mp){
        //     for(auto x:it.second){
        //         ans.push_back(x);
        //         arr = ans;
        //     }
        // }
        
        // optimize approach:
        vector<pair<int, pair<int, int>>> ans;
        for(auto i= 0; i<n; i++){
            int ele = arr[i];
            ans.push_back({abs(x - ele), {i, arr[i]}});
        }
        sort(ans.begin(), ans.end());
        arr.clear();
        for(auto &it:ans){
            arr.push_back(it.second.second);
        }
        
    }
};
