class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // T.C = O(N)
        
        int n = fruits.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                cnt = max(cnt, j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
        
    }
};
