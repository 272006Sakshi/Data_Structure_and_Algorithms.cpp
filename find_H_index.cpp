class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        // map<int,int> freq; 

        // // Count frequency of each citation
        // for (int c : citations) {
        //     freq[c]++;
        // }

        // int total = 0; 
        // int h = 0;

        // for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        //     total += it->second;  
        //     if (total >= it->first) {
        //         h = max(h, it->first);  
        //     }
        // }

        
        // // if (total >= n) {
        // //     h = max(h, n);
        // // }

        // return h;
        
        sort(citations.rbegin(), citations.rend());
        int i = 0;
        while(i<n && citations[i]>=i+1){
            i++;
        }
        return i;
    }
};
