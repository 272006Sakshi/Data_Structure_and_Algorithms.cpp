class Solution {
public:
    int pivotInteger(int n) {
        vector<int> arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }

        int total = 0;
        for(int j = 0; j < arr.size(); j++){
            total += arr[j];
        }

        int leftS = 0;
        for(int k = 0; k < arr.size(); k++){
            int rightS = total - leftS - arr[k];
            if(leftS == rightS){
                return arr[k];
            }
            leftS += arr[k];
        }

        return -1; 
   }
};
