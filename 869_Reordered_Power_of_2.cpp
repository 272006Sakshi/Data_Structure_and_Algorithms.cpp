class Solution {
public:
    bool reorderedPowerOf2(int n) {

        // T.C = constant complexity
        string s = to_string(n); // convert into string     //
        sort(s.begin(), s.end()); 

        // 10^9 is Constraint
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            string p = to_string(power);
            sort(p.begin(), p.end()); 
            if (s == p){
                return true;
            }    
        }
        return false;
    }
};
