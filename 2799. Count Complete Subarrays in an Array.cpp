class Solution {
public:
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
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        int k = st.size(); 
        return subarrayCnt(nums, k) - subarrayCnt(nums, k-1);
    }
};
