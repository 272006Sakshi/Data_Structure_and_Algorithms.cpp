class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n/2];
        int cnt = 1;
        int maj = nums[0];

        for(int i = 1; i<n; i++){
            if(cnt == 0){
                maj = nums[i];
                cnt++;
            }
            else if(nums[i] == maj){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return maj;
    }
};
