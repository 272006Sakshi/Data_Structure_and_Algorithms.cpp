class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      // t.c - O(Nlogn+Mlogm)
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i =0,j =0;
        while(i<n && j<m){
            if(i!=0 && nums1[i] == nums1[i-1])i++;
            if(j!=0 && nums2[j] == nums2[j-1])j++;
            else if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++, j++;
            }
            else if(nums1[i] < nums2[j])i++;
            else j++;
        }
        return ans;
    }
};
