class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Approach-1: Brute 
        // O(n^3)

        // int n = nums.size();
        // int res = INT_MAX;
        // if(n<3) return -1;
        // for(int i=0;i<n-2; i++){
        //     for(int j = i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]==nums[j] && nums[j]==nums[k]){
        //                 int mini = abs(i-j)+abs(j-k)+abs(k-i);
        //                 res = min(mini, res);
        //             }
                    
        //         }
        //     }
        // }
        // if(res==INT_MAX) return -1;
        // return res;

        // Approach-2
        // O(n)
        int n = nums.size();
        int res = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for(int k = 0;k<n;k++){
            mp[nums[k]].push_back(k);
            if(mp[nums[k]].size()>=3){
                vector<int> &ind = mp[nums[k]];
                int i = ind[ind.size()-3];
                res = min(res, 2*(k-i));
            }
        }
        return res==INT_MAX?-1:res;

    }
};
