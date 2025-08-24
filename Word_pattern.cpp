class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // set<char> st1;
        // set<char> st2;
        
        // for(auto &str:pattern){
        //     st1.insert(str);
        // }

        // for(int i = 0; i<s.length(); i++){
        //     st2.insert(s[i]);
        // }
        // if(st1.size() != st2.size()){
        //     return false;
        // }
        // return true;
        vector<string> words;
        string word = "";

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word); // last word

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (p2w.count(c) && p2w[c] != w) return false;
            if (w2p.count(w) && w2p[w] != c) return false;

            p2w[c] = w;
            w2p[w] = c;
        }

        return true;
        
    }
};
