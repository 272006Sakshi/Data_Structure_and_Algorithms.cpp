class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string &w : words){
            long long sum = 0;

            for(char c:w){
                sum+=weights[c-'a'];
            }

            int rem = sum%26;
            char mpchar = 'z' - rem;
            res+=mpchar;
        }
        return res;
    }
};
