class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> posEle;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=0){
                posEle.push_back(nums[i]);
            }
        }

        int l = posEle.size();
        if(l==0) return nums;
        k = k%l;
        // reverse(posEle.begin(), posEle.end());
        // reverse(posEle.begin(), posEle.begin()+k);
        // reverse(posEle.begin()+k, posEle.end());
        rotate(posEle.begin(), posEle.begin()+k, posEle.end());

        int ind = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>=0){
                nums[i] = posEle[ind++];
            }
        }
        return nums;
    }
};©leetcode
