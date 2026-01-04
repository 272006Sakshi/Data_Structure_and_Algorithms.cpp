class Solution {
public:
    string largestEven(string s) {
        int l = s.length();
        for(int i = l-1;i>=0; i--){
            if(s[i] == '1'){
                s.pop_back();
            }
            else{
                break;
            }
        }
        return s;
        
    }
};
