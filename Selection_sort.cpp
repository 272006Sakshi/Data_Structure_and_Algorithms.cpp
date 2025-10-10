class Solution {
public:
    //     selection sort O(n^2)

    void selectionsort(vector<int>& nums, int n){
        for(int i = 0; i<n-1; i++){
            int minIdx = i;
            for(int j = i+1; j<n; j++){
                if(nums[j]<nums[minIdx]){
                    minIdx = j;
                }
            }
            swap(nums[i], nums[minIdx]);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        selectionsort(nums, n);
        
        return nums;
    }
};
