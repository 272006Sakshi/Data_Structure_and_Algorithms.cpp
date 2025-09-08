class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total  = 0;
        int leftS = 0;
        for(int i = 0; i<n; i++){
            total+=nums[i];

        }
        for(int j = 0;j<n; j++){
            int rightS = total - leftS - nums[j];
            if(leftS == rightS){
                return j;
            }
            leftS+=nums[j];
        }
        return -1;
    }
};
