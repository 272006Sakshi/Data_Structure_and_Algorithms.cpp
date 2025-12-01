class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // T.C: O(n)   S.C: O(n)
        // int res;
        // unordered_map<int, int> mp;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        // }
        // for(auto &it:mp){
        //     if(it.second>n/2) return res = it.first;
        // }
        // return res;
       

       // Boyer Moore Voting Algorithm
       // T.C: O(n)   S.C: O(1)
        int  = 0, cnt = 0;
        for(int i = 0; i<n; i++){
            if(cnt == 0){
                candidate = nums[i];
            }

            if(candidate == nums[i]){
                cnt+=1;
            }
            else{
                cnt-=1;
            }
        }
        return candidate;
    }
};
