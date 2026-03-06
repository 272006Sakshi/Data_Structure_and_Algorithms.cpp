class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        // int i = 0;
        // while(i<s.length()){
        //     if(s[i]=='1'){
        //         cnt++;
        //         while(i<s.length() && s[i]=='1'){
        //             i++;
        //         }
        //     }
        //     else{
        //         i++;
        //     }
        //     if(cnt>1) return false;
        // }
        // return true;

        int n = s.length();
        for(int i = 0; i<n-1; i++){
            if(s[i]=='0' && s[i+1]=='1'){
                return false;
            }
        }
        return true;
    }
};
