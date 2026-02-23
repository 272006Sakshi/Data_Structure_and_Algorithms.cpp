class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        bool activeP1 = true;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2==1){
                activeP1 = !activeP1;
            }
            if((i+1)%6==0){
                activeP1 = !activeP1;
            }
            if(activeP1){
                p1+=nums[i];
            }
            else{
                p2+=nums[i];
            } 
        }
        int ans = p1-p2;
        return ans;
    }    
};
