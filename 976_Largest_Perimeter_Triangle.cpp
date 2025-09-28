class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      // T.C : O(Nlogn) S.C: O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = n-1; i>=2; i--){
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];

            if(a+b>c) return a+b+c;
        }
        return 0;
        
    }
};
