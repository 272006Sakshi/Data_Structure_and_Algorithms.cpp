class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ind = 0;
        for(int i = 0; i<t.length(); i++){
            if(ind<s.length() && s[ind] == t[i]){
                ind++;
            }
        }
        if(ind == s.length()){
            return true;
        }
        return false;
    }
};
