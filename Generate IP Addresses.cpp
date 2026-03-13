class Solution {
  public:
    bool check(string &s){
        int l = s.length();
        if(l<=0 or l>3) return false;
        if(s[0]=='0' and l>1) return false;
        int val = stoi(s);
        if(val<0 or val>255) return false;
        return true;
    }
    string ValidIpAddress(string &s, int n, int i, int j, int k){
        string str1 = s.substr(0, i+1);
        string str2 = s.substr(i+1, j-i);
        string str3 = s.substr(j+1, k-j);
        string str4 = s.substr(k+1, n-1-k);
        
        if(check(str1) and check(str2) and check(str3) and check(str4)){
            return str1+"."+str2+"."+str3+"."+str4;
        }
        return "";
    }
    vector<string> generateIp(string &s) {
        // code here
        int n = s.length();
        vector<string> res;
        for(int i = 0;i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n;k++){
                    string st = ValidIpAddress(s, n, i, j, k);
                    if(st.size()>0){
                        res.push_back(st);
                    }
                }
            }
        }
        return res;
    }
};
