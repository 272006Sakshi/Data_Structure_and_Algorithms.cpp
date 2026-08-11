class Solution {
public:
    int dp[502][502];
    int possibility(vector<int>& piles, int l, int r){ 
        if(l>r) return 0;
        // [5, 3, 4, 5]
        //  l        r
        if(dp[l][r]!=-1) return dp[l][r];
        int leftWala = piles[l]+min(possibility(piles, l+2, r), possibility(piles, l+1, r-1));
        int rightWala = piles[r]+min(possibility(piles, l, r-2), possibility(piles, l+1, r-1));

        return dp[l][r] = max(leftWala, rightWala);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = 0;
        memset(dp, -1, sizeof(dp));
        for(int pile:piles){
            total+=pile;
        }
        int A_score = possibility(piles, 0, n-1);
        return A_score > total/2;
    }
};
