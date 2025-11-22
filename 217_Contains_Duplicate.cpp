class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Approach - 1
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i = 1; i<n; i++){
        //     if(nums[i] == nums[i - 1]){
        //         return true;
        //     }
        
        // }
        // return false;

       // Approach -2  // using map
        // unordered_map<int, int> mp;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>1) return true;
        // }

        //Approach - 3 // using set
        unordered_set<int> st;
        for(int x : nums){
            if(st.count(x)) return true; 
            st.insert(x);
        }
        
        return false;
    }
};

