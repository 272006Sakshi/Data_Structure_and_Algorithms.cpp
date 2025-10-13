class Solution {
public:
    bool isAnagram(string s1, string s2){
        int l = s1.length();
        int m = s2.length();

        if(l!=m) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        for(int i=0; i<l; i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int j = 1;
        while(j<words.size()){
            if(isAnagram(words[j], words[j-1])){
                words.erase(words.begin() + j);
            }
            else{
                j++;
            }
        }
        return words;
    }
};
