class Solution {
public:
    void getsubsets(vector<int>& nums, vector<int> &res, int ind, vector<vector<int>> &allsubsets){
        if(ind == nums.size()){
            allsubsets.push_back({res});
            return;
        }
        res.push_back(nums[ind]);
        getsubsets(nums, res, ind+1, allsubsets);

        // backtracking
        res.pop_back();
        // check duplicate: if duplicate present we'll skip after 
        int i = ind+1;
        while(i<nums.size() && nums[i] == nums[i-1]){
            i++;
        }
        getsubsets(nums, res, i, allsubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort array: for handle duplicates
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubsets;
        vector<int> res;
        getsubsets(nums, res, 0, allsubsets);
        return allsubsets;
    }
};
