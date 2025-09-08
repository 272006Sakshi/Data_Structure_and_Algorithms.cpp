class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int total = 0;
        for(int j = 0; j < arr.size(); j++){
            total += arr[j];
        }

        int leftS = 0;
        for(int k = 0; k < arr.size(); k++){
            int rightS = total - leftS - arr[k];
            if(leftS == rightS){
                return k;
            }
            leftS += arr[k];
        }

        return -1;
    }
};
