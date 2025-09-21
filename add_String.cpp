class Solution {
public:
    string addStrings(string num1, string num2) {
        // long long n1 = stoll(num1);
        // long long n2 = stoll(num2);
        // long long res = n1 + n2;
        // return to_string(res);

        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
