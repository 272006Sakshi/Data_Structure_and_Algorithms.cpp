class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        for (char it : s) {
            if (it == '(' || it == '{' || it == '[') {
                stc.push(it);
            } else {
                if (stc.empty()) return false;
                char ch = stc.top();
                stc.pop();
                if (!((it == ')' && ch == '(') ||
                      (it == ']' && ch == '[') ||
                      (it == '}' && ch == '{'))) {
                    return false;
                }
            }
        }
        return stc.empty();
    }
};
