class Solution {
  public:
// T.C: O(N)
// S.C: O(1)
    int Max_subarray(vector<int> &arr, int k){
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<int, int> freq;
        while(j<arr.size()){
            freq[arr[j]]++;
            while(freq.size()>k){
                freq[arr[i]]--;
                if(freq[arr[i]]==0){
                    freq.erase(arr[i]);
                }
                i++;
            }
            res=max(res, j-i+1);
            j++;
        }
        return res;
    }
    
    int totalElements(vector<int> &arr) {
        // code here
        return Max_subarray(arr, 2);
    }
};
