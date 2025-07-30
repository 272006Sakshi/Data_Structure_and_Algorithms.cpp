class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        // arr[] = [10, 2, -2, -20, 10], k = -10
        int n = arr.size();
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> preSum;
        
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum == k) cnt++;
            
            if(preSum.find(sum - k) != preSum.end()){
                cnt += preSum[sum-k];
            }
            preSum[sum]++;
        }
        return cnt;
        
    }
};
