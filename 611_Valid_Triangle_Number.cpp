class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        // T.C: O(n^3) , S.C : O(1)
        // int cnt = 0;
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i<n-2; ++i){
        //     for(int j = i+1; j<n-1; ++j){
        //         for(int k = j+1; k<n; ++k){
        //             if(nums[i]+nums[j] > nums[k]){
        //                 cnt++;
        //             }
        //         }
        //     }
        // }
        // return cnt;

        // T.C = O(n^2)   S.C: O(1)
        int cnt = 0;
        sort(nums.begin(), nums.end());

        for(int k = n-1; k>=2; k--){
            int i = 0, j = k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    cnt += (j-i);
                    j--;
                }
                else{
                    i++;
                }
                
            }
        }
        return cnt;
    }
};
