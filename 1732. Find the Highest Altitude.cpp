class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> prefixArr(n+1, 0);
        for(int i=0; i<n; i++){
            prefixArr[i+1] = prefixArr[i]+gain[i];
        }
        return *max_element(prefixArr.begin(), prefixArr.end());
    }
};
