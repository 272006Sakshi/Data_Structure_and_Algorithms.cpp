class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int l= 0;
        set<char> st;
        for(int r = 0; r<n; r++){
        
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
