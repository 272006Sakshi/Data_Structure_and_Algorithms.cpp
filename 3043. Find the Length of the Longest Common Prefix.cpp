class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto &x:arr1){
            while(x>0){
                st.insert(x);
                x/=10;
            }
        }
        int res = 0;
        for(auto &y:arr2){
            int size = to_string(y).size();
            while(y>0){
                if(st.count(y)){
                    res = max(res, size);
                    break;
                }
                y/=10;
                size--;
            }
        }
        return res;
        
    }
};
