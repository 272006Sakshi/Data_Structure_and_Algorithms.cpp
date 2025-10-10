class Solution {
public:
    // mergesort
    void merge(vector<int> &arr, int l, int m, int r, vector<int> &temp){
        int i = l, j = m+1, k = l;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (int p = l; p <= r; ++p) arr[p] = temp[p];
    }
    void mergesort(vector<int> &arr, int l, int r, vector<int> &temp){
        if(l>=r) return;
        int m = l+(r-l)/2;
        mergesort(arr, l, m, temp);
        mergesort(arr, m+1, r, temp);
        merge(arr, l, m, r, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
      
        if(n<=1) return nums;
        vector<int> temp(n);
        mergesort(nums, 0, n-1, temp);
        return nums;
    }
};
