class Solution {
public:
    // T.C: O(N) 
    // S.C: O(k) --> character frequency map
    string minWindow(string s, string t) {
        int l = s.length();
        unordered_map<int, int> freq;
        for(int i = 0; i<t.length(); i++){
            freq[t[i]]++;
        }
        int reqCnt = t.length();
        int i = 0, j = 0;
        int miniWindow = INT_MAX;
        int start_ind = 0;
        while(j<l){
            if(freq[s[j]]>0){
                reqCnt--;
            }
            freq[s[j]]--;

            while(reqCnt == 0){
                int currWindow = j-i+1;
                if(miniWindow>currWindow){
                    miniWindow=currWindow;
                    start_ind = i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0){
                    reqCnt++;
                }
                i++;
            }
            j++;
        }
        if(miniWindow == INT_MAX){
            return "";
        }
        return s.substr(start_ind, miniWindow);
    }
};
