class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int l = 0, r = 0, zeros = 0;
        int maxlen  = 0;
        while(r<arr.size()){
            if(arr[r] == 0){
                zeros++;
            }
            if(zeros>k){
                if(arr[l]==0)zeros--;
                l++;
                
            }
            if(zeros<=k){
                int len = r-l+1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};
