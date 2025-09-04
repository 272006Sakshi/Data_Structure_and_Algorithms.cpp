class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        //Brute Force: O(nlogn)
      // Approach : Square all numbers + sorting
        // for(int i = 0; i<n; i++){
        //     nums[i] = nums[i]*nums[i];

        // }
        // sort(nums.begin(), nums.end());
        // return nums;

        // Using Two Pointers
        
        // T.C = O(N) , S.C = O(1)
        int l = 0, r = n-1;
        int pos = n-1;
        vector<int> res(n);

        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                res[pos] = nums[l]*nums[l];
                l++;
            }
            else{
                res[pos] = nums[r]*nums[r];
                r--;
            }
            pos--;
        }

        for(int i = 0; i<n; i++){
            nums[i] = res[i];
        }
        return nums;
    }
};
