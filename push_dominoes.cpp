class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = dominoes.length();
        vector<int> rightNearestL(l);
        vector<int> leftNearestR(l);
        
        // left to right traverse
        for(int i = 0; i<l; i++){
            if(dominoes[i] == 'R'){
                leftNearestR[i] = i;
            }
            else if(dominoes[i] == '.'){
                leftNearestR[i] = i>0 ? leftNearestR[i-1] : -1;
            }
            else{
                leftNearestR[i] = -1;
            }
        }
        // right to left traverse
        for(int i = l-1; i>=0; i--){
            if(dominoes[i] == 'L'){
                rightNearestL[i] = i;
            }
            else if(dominoes[i] == '.'){
                rightNearestL[i] = i<l-1 ? rightNearestL[i+1] : -1;
            }
            else{
                rightNearestL[i] = -1;
            }
        }

        string ans(l, ' ');
        for(int i = 0; i<l; i++){
            int distr_L = abs(i - rightNearestL[i]);
            int distl_R = abs(i - leftNearestR[i]);

            if(rightNearestL[i] == leftNearestR[i]){
                ans[i] = '.';
            }
            else if(leftNearestR[i] == -1){
                ans[i] = 'L';
            }
            else if(rightNearestL[i] == -1){
                ans[i] = 'R';
            }
            else if(distr_L == distl_R){
                ans[i] = '.';
            }
            else{
                if(distr_L < distl_R) ans[i] = 'L';
                else ans[i] = 'R';
            }
        }
        return ans;

    }
};
