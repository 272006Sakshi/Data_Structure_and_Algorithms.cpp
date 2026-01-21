class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // brute approach
        int n = nums.size();
        // vector<int> res(n, -1);
        // for(int i = 0; i<n; i++){
        //     for(int val = 0; val<=nums[i]; val++){
        //         if((val | (val+1)) == nums[i]){
        //             res[i] = val;
        //             break;
        //         }
        //     }
        // }
        // return res;

       // Optimize approach
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(nums[i]==2){
                res.push_back(-1);
                continue;
            }
            bool flag = false;
            for(int j = 1; j<32; j++){
                if((nums[i]&(1<<j)) >0){ // bit set 
                    continue;
                }
                int prev_bit = j-1;
                //set 0
                int val = (nums[i]^(1<<(j-1)));
                res.push_back(val);
                flag = true;
                break;
            }
            if(flag == false) res.push_back(-1);
        }
        return res;

    }
};
