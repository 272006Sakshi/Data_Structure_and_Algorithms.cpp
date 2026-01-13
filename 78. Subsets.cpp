class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int> &res, int idx, vector<vector<int>> &allSubsets){
        if(idx==nums.size()){
            allSubsets.push_back({res});
            return;
        }    
        //include
        res.push_back(nums[idx]);
        getSubsets(nums, res, idx+1, allSubsets);
        //backtracking
        res.pop_back();
        getSubsets(nums, res, idx+1, allSubsets); // exclude
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> allSubsets;  
        vector<int> res;
        getSubsets(nums, res, 0, allSubsets);
        return allSubsets;
    }
};
