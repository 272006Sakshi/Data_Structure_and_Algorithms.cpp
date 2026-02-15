class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        
        unordered_map<int, int> mp;
        for(int i = 0; i<bulbs.size(); i++){
            mp[bulbs[i]]++;

        }
        vector<int> res;
        for(auto &it:mp){
            if(it.second%2!=0){
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
