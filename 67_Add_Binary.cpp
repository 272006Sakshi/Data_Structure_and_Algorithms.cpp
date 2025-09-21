class Solution {
public:
    string addBinary(string a, string b) {
        // int n1 = stoi(a, 0, 2);  
        // int n2 = stoi(b, 0, 2);
        // int sum = n1 + n2;
        // return bitset<10000>(sum).to_string().substr(bitset<10000>(sum).to_string().find('1')); 

        string result = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;

    }
};
