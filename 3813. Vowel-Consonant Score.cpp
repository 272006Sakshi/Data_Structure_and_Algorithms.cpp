class Solution {
public:
    int vowelConsonantScore(string s) {
        // T.C: O(n)
        // S.C: O(1)
        int l = s.length();
        int cons = 0;
        int vow = 0;
        for(int i = 0; i<l; i++){
            if(s[i]>='a' && s[i]<='z'){
                if(s[i] == 'a' || s[i]=='e' || s[i]== 'i' || s[i]=='o' || s[i]=='u'){
                    vow++;
                }
                else{
                    cons++;
                }
            }    
        }
        if(cons==0) return 0;
        return vow/cons;
    }
};
