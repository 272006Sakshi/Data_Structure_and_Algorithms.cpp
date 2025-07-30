class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int TotSum = 0;
        int leftSum = 0;
        for(int i = 0; i<n; i++){
            TotSum += arr[i];
        }
        for(int i= 0; i<n; i++){
            int rightSum = TotSum - leftSum - arr[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += arr[i];
        }
        return -1;
    }
};
