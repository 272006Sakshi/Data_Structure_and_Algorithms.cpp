class Solution {
public:
    bool isPalindrome(string s) {
        
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return tolower(c); });

        // remove non-alphanumeric
        s = regex_replace(s, regex("[^a-z0-9]"), "");

        // check palindrome
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
