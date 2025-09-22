class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
      // T.C = O(n), S.C = O(100)~O(1)
        // two pass
        // store frequencies of each elements

        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        // }
        // // find max frequencies 

        // int maxfreq = 0;
        // for(auto& it:mp){
        //     maxfreq = max(maxfreq, it.second);
        // }

        // int total = 0;
        // for(auto& it:mp){
        //     if(it.second == maxfreq){
        //         total+=maxfreq;
        //     }
        // }


        // one pass solution
        int maxfreq = 0;
        int total = 0;
        for(int i = 0; i<n; i++){
            int freq = ++mp[nums[i]];
            if(freq>maxfreq){
                maxfreq = freq;
                total = freq;
            }
            else if(freq == maxfreq){
                total+=maxfreq;
            }
        }
        return total;
    }
};
