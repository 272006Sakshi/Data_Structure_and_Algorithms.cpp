class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
      // Input: s = "abacab"
      // Output: [293, 294]
      
        int l = s.length();
        vector<int> first(26, -1);  // for 1st occurance character
        vector<int> last(26, -1);  // for last occurance character
        vector<int> res;
        
        for(int i= 0; i<l; i++){
            int idx = s[i] - 'a'; 
            if(first[idx] == -1){
                first[idx] = i;  // update index 
            }
            last[idx] = i;
        }
        for(int i = 0; i<26; i++){
            if(first[i] != -1 && last[i] != -1 && first[i]<last[i]){
                int sum = 0;
                for(int j = first[i]+1; j<last[i]; j++){   // a (b + a + c) a b   & a b (a + c + a) b
                    sum+=s[j];
                }
                if(sum != 0){
                    res.push_back(sum);
                }
            }
        }
        return res;
    }
};
