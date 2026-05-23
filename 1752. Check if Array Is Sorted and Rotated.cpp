class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        // vector<int> sortedArr(n);
        // for(int i=0;i<n;i++){
        //     int idx=0;
        //     for(int j=i;j<n;j++){
        //         sortedArr[idx] = nums[j];
        //         idx++;
        //     }
        //     for(int j=0;j<i;j++){
        //         sortedArr[idx] = nums[j];
        //         idx++;
        //     }
        //     bool flag = true;
        //     for(int k=0;k<n-1;k++){
        //         if(sortedArr[k]>sortedArr[k+1]){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag==true) return true;
        // }
        // return false;

        // Approach: 2
        int peak_ele = 0;
        for(int i =0;i<n; i++){
            if(nums[i]>nums[(i+1)%n]){
                peak_ele++;
            }
        }
        if(peak_ele<=1) return true;
        else{
            return false;
        }    
    }
};
