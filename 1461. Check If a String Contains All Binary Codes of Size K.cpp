class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int num = pow(2, k);
        set<string> st;
        for(int i = k; i<=s.length(); i++){
            string binary = s.substr(i-k, k);
            if(!st.count(binary)){
                st.insert(binary);
                num--;
            }
            if(num==0){
                return true;
            }
        }
        return false;
    }
};
