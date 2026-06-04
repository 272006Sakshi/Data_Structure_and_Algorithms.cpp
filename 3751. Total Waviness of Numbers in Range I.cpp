class Solution {
public:
    int waviNess(int n){
        string s = to_string(n);
        if(s.size()<3) return 0;
        int cnt = 0;
        for(int i = 1; i<s.size()-1; i++){
            int l = s[i-1]-'0';
            int r = s[i+1]-'0';
            int mid = s[i]-'0';
            if(mid>l && mid>r){
                cnt++;
            }
            else if(mid<l && mid<r) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int j = num1; j<=num2; j++){
            res += waviNess(j);
        }
        return res;
    }
};
