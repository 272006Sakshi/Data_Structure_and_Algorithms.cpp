class Solution {
public:
    int dp[22][22];
    int possibility(vector<int>& nums, int l, int r){ 
        if(l>r) return 0;
        // [5, 3, 4, 5]
        //  l        r
        if(dp[l][r]!=-1) return dp[l][r];
        int leftWala = nums[l]+min(possibility(nums, l+2, r), possibility(nums, l+1, r-1));
        int rightWala = nums[r]+min(possibility(nums, l, r-2), possibility(nums, l+1, r-1));

        return dp[l][r] = max(leftWala, rightWala);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        memset(dp, -1, sizeof(dp));
        for(int num:nums){
            total+=num;
        }
        int player1 = possibility(nums, 0, n-1);
        int player2 = total-player1;
        return player1>=player2;
    }
};
