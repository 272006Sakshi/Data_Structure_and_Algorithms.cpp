class Solution {
public:
    int maximum69Number (int num) {
        // approach:
        // num ko string me change karenge. uske baad left most me jo '6' hoga usko change('9') 
        // kar denge, then num ko return kar denge
        // T.C - O(N)
        string n = to_string(num);
        for(int i= 0; i<n.size(); i++){
            if(n[i] == '6'){
                n[i] = '9';
                break;
            }
        }
        return stoi(n);
    }
};
