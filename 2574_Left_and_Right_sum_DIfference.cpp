class Solution {
public:
    vector<int> leftRightDifference(vector<int>& arr) {
        int total = 0;
        vector<int> res;
        for(int j = 0; j < arr.size(); j++){
            total += arr[j];
        }

        int leftS = 0;
        for(int k = 0; k < arr.size(); k++){
            int rightS = total - leftS - arr[k];
            int num = abs(leftS - rightS);
            res.push_back(num);
            leftS += arr[k];
        }
        return res;

    }
};
