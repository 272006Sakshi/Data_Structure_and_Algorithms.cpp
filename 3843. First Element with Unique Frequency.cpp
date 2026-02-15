class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        unordered_map<int,int>freq;
        for(auto &it:mp){
            freq[it.second]++;
        }
        for(int ele:nums){
            if(freq[mp[ele]]==1) return ele;
        }
        return -1;
    }
};
