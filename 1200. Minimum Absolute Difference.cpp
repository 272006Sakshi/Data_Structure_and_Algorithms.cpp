class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for(int i=1;i<n;i++){
            min_diff = min(min_diff, arr[i]-arr[i-1]);
        }

        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1] == min_diff){
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
