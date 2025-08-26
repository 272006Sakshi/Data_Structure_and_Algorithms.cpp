class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int l1 = s1.length();
        int l2 = s2.length();
        
        int i = 0, j = 0;
        
        
        while(i<l1 && j<l2){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
    
        return i==l1;
    }
};
