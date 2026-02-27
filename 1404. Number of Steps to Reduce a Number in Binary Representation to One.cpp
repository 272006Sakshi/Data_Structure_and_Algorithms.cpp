class Solution {
public:
    int numSteps(string s) {
      // T.C: O(n^2)
        // int cnt = 0;
    
        // while (s != "1") {
        //     if (s.back() == '0') {
        //     // even--> divide by 2
        //        s.pop_back();
        //     } else {
        //        int i = s.length() - 1;
        //        // binary addition
        //        while (i >= 0 && s[i] == '1') {
        //            s[i] = '0';
        //            i--;
        //         }
            
        //         if (i < 0) {
        //            s = '1' + s;
        //         } else {
        //            s[i] = '1';
        //         }
        //     }
        //     cnt++;
        // }
    
        // return cnt;



        // Optimal Approach: O(n)

        int count = 0;
        int carry = 0;
        for(int i = s.length()-1; i>=1; i--){
            if((s[i]-'0'+carry) % 2==1){
                count+=2;
                carry = 1;
            }
            else{
                count+=1;
            }
        }
        return count + carry;
    }
};
