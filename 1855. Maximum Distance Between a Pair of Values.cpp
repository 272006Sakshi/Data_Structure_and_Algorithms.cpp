class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // T.C: O(l1+l2)
        // S.C: O(1)
        int l1 = nums1.size();
        int l2 = nums2.size();
        int dist = 0;
        int i = 0, j = 0;
        while(i<l1 && j<l2){
            if(i<=j && nums1[i]<=nums2[j]){
                dist = max(dist, j-i);
                j++;
            }
            else if(i<=j){
                i++;
            }
            else{
                j++;
            }
        }
        return dist;
    }
};
