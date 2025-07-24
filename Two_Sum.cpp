class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        // using map
        unordered_map<int, int> ele_Idx;
        for(int i = 0; i<n; i++){
            int diff = target - nums[i];
            if(ele_Idx.find(diff) != ele_Idx.end()){
                return {i, ele_Idx[diff]};
            }
            ele_Idx[nums[i]] = i;
        }
        return {};
        
    }
};
