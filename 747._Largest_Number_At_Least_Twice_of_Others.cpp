class Solution {
public:
    int dominantIndex(vector<int>& nums) {
         //    int n = nums.size();
        //     int maxVal = -1, second = -1;
        //     int maxIdx = -1;

    //         for (int i = 0; i < n; i++) {
    //            if (nums[i] > maxVal) {
    //         // shift current max down to second
    //               second = maxVal;
    //               maxVal = nums[i];    maxIdx = i;
    //            } 
    //           else if (nums[i] > second) {
    //             second = nums[i];
    //           }
    //        }

    //        return (maxVal >= 2 * second) ? maxIdx : -1;
        // using sorting
          int n = nums.size();
    
          vector<pair<int, int>> pairs;
          for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
          }

         // sort by value
         sort(pairs.begin(), pairs.end());

         int largest = pairs[n-1].first;
         int secondLargest = pairs[n-2].first;
         int indexLargest = pairs[n-1].second;

         return (largest >= 2 * secondLargest) ? indexLargest : -1;
        }
};

