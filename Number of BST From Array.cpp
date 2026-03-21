class Solution {
  public:
    vector<int> catlan = {1, 1, 2, 5, 14, 42};
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> bstCount;
        for(int i = 0; i<n; i++)
        {
            int lower = 0;
            int greater = 0;
            for(int j = 0;j<n;j++)
            {
                if(arr[i]<arr[j])
                {
                    greater++;
                }
                else if(arr[i]>arr[j])
                {
                    lower++;
                }
            }
            bstCount.push_back(catlan[lower]*catlan[greater]);
        }
        return bstCount;
    }
};
