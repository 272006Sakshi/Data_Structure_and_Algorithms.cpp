class Solution {
  public:
// T.C: O(n+m)
// S.C: O(1)

    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0;
        int j = m-1;
        
        int mindiff = INT_MAX;
        vector<int> res(2, 0);
        while(i<n && j>=0){
            int Pair_Sum = arr1[i]+arr2[j];
            int diff = Pair_Sum-x;
            
            if(abs(diff) < mindiff){
                mindiff = abs(diff);
                res[0] = arr1[i];
                res[1] = arr2[j];
            }
            if(diff>0){
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};
