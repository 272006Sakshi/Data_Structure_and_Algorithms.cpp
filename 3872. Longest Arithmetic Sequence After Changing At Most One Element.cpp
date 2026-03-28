class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix(n, 2);
        vector<int> suffix(n, 2);

        int res = 2;
        prefix[0] = 1;
        for(int i=2;i<n;i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]){
                prefix[i] = prefix[i-1]+1;
            }
            else{
                prefix[i] = 2;
            }
        }
        suffix[n-1]=1;
        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i] = 2;
            }
        }
        for(int i=0;i<n;i++){
             if(i) res = max(res,prefix[i-1]+1);
            if(i+1<n) res = max(res , suffix[i+1]+1);

            if(i && i+1<n){
                int diff = nums[i+1]-nums[i-1];
                if(diff%2) continue;
                int size = 1;
                if(i-2>=0 && nums[i-1]-nums[i-2]==diff/2){
                    size+=prefix[i-1];
                }
                else size+=1;
                if(i+2<n && nums[i+2]-nums[i+1]==diff/2) size+=suffix[i+1];
                else size+=1;
                res = max(res,size);
            }
        }

        return res;
    }
};
