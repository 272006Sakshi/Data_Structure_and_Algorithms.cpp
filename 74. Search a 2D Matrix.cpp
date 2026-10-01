class Solution {
public:
    //T.C: O(log(m) + log(n))
    //S.C: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = n * m - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int r = mid / m;
            int c = mid % m;
            int cell = matrix[r][c];

            if (cell == target) {
                return true;
            } else if (cell < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;      
    }
};
