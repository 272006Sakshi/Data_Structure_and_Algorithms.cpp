class Solution {
public:
// T.C =O(N)
// S.C = O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        numbers.insert(numbers.begin(), 0);
        int n = numbers.size()-1;
        int l = 1;
        int r = n;

        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum == target){
                return {l, r};
            }
            else if(sum>target){
                r--;
            }
            else{
                l++;
            }
        }
        return {-1};
    }
};
