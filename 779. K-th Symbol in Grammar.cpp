class Solution {
public:
    int kthGrammar(int n, int k) {
        int len = pow(2, n-1);
        int mid = len/2;

        // Base condition
        if(n==1 && k==1) return 0;
        
        else if(k<=mid){
            return kthGrammar(n-1, k);
        }
        else{
            return !kthGrammar(n-1, k-mid);
        }
    }
};
