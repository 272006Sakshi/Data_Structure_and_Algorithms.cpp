class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //T.C: O(n)
        //S.C: O(n)
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i = 0; i<n; i++){
            for(int val = 0; val<=nums[i]; val++){
                if((val | (val+1)) == nums[i]){
                    res[i] = val;
                    break;
                }
            }
        }
        return res;
    }
};
