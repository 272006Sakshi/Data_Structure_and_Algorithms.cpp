class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(),prices.end());
        
        int mini = 0;
        int maxi = 0;
        
        int cnt = n;
        int i=0;
        
        while(cnt > 0){
            mini += prices[i];
            cnt--;
            cnt -=k;
            i++;
        }
        
        cnt = n;
        i = n-1;
        while(cnt > 0){
            maxi += prices[i];
            cnt--;
            cnt -=k;
            i--;
        }
        
        return {mini,maxi};
    }
};
