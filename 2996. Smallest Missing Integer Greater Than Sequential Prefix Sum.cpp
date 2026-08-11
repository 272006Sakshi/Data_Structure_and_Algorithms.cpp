// T.C: O(N)
// S.C: O(N)
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int Seqsum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                Seqsum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());
        while(st.count(Seqsum)){
            Seqsum++;
        }
        return Seqsum;
    }
};
