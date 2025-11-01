class Solution {
public:
    bool isValid(string s) {
        stack<char> dabba;
        for (char it : s) {
            if (it == '(' || it == '{' || it == '[') {
                dabba.push(it);
            } else {
                if (dabba.empty()) return false;
                char ch = dabba.top();
                dabba.pop();
                if (!((it == ')' && ch == '(') ||
                      (it == ']' && ch == '[') ||
                      (it == '}' && ch == '{'))) {
                    return false;
                }
            }
        }
        return dabba.empty();
    }
};
