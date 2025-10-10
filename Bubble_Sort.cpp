class Solution {
public:
     //     bubble sort O(n^2)
    void bubblesort(vector<int>& nums, int n){

        bubble sort O(n^2)

        for(int i = 0; i<n-1; i++){
            bool swapped = false;
            for(int j = 0; j<n-i-1; j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bubblesort(nums, n);
        return nums;
    }
};
