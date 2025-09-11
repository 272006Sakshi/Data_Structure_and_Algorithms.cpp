class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int jump = 0, last = 0;
        int maxi = 0;   // maxi = 7, jump = 3, last = 7 // 
        
        if(arr[0] == 0) return -1;
        if(n<2) return 0;
        
        for(int i =0; i<n; i++){
            maxi = max(maxi, i+arr[i]);
            
            if(i == last){
                jump++;
                last=maxi;
                if(last>=(n-1)){
                    return jump;
                }
            }
        }
        return -1;
        
    }
};
