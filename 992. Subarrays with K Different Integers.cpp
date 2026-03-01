class Solution {
public:
// T.C: O(N)
// S.C: O(N)
    int subarrayCnt(vector<int> &nums, int k){
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<int, int> freq;
        while(j<nums.size()){
            freq[nums[j]]++;
            while(freq.size()>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayCnt(nums, k) - subarrayCnt(nums, k-1);
    }
};
