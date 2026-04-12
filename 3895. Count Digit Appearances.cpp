class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        char d = digit+'0';
        for(int &i:nums){
            string s = to_string(i);
            for(char &ch:s){
                if(ch==d) cnt++;
            }
        }
        return cnt;
    }
};
