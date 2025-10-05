class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1 = s.length(), l2 = t.length();

        if(l1 != l2) return false;

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // for(int i = 0; i<l1; i++){
        //     if(s[i] != t[i]) return false;
        // }
        // return true;

        vector<int> mp(26, 0);
        

        for(int i = 0; i<l1; i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(int c: mp){
            if(c != 0) return false;
        }
        return true;

        
    }
};
