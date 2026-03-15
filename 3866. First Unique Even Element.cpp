class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int num:nums){
            if(num%2==0 && mp[num] == 1){
                return num;
            }
        }
        return -1;
    }
};
