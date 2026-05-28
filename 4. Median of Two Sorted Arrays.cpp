class Solution {
public:
// T.C: O(m+n log(m+n))
// s.c: O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int>mergedArr;
        for(auto &num:nums1){
            mergedArr.push_back(num);
        }
        for(auto &num:nums2){
            mergedArr.push_back(num);
        }
        sort(mergedArr.begin(), mergedArr.end());
        int total_len = mergedArr.size();
        if(total_len%2==1){
            return mergedArr[total_len/2];
        }
        else{
            int prev = mergedArr[total_len/2-1];
            int mid = mergedArr[total_len/2];
            return (prev+mid)/2.0;
        }
    }
};
