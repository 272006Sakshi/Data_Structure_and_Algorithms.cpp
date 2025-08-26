class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiago = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int len = dimensions[i][0];
            int wid = dimensions[i][1];
            int currDiago = len * len + wid * wid;

            if (currDiago > maxDiago || (currDiago == maxDiago && len * wid > maxArea)) {
                maxDiago = currDiago;
                maxArea = len * wid;
            }
        }
        return maxArea;
    }
};
