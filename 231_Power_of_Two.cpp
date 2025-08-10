class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        double res = log2(n);
        return res == (int)res;
    }
};     
