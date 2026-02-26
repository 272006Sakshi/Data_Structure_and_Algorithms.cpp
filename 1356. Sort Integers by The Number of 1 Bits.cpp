class Solution {
public:
    int cntBits(int n){
        int count_One = 0;
        while(n!=0){
            count_One+=(n&1);
            n>>=1;
        }
        return count_One;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // lambda function
        auto lambda = [&](int &a, int &b){
            int countOne_a = cntBits(a);
            int countOne_b = cntBits(b);
            if(countOne_a==countOne_b){
                return a<b;
            }
            else{
                return countOne_a<countOne_b;
            }
        };
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};
