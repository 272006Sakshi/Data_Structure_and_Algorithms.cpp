class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false; //From left to right, -121. From right to left, it becomes 121-. it is not a palindrome.
        long reverse =0;
        long long temp =x;

        while(temp!=0){
            int digit = temp%10;
            reverse = (reverse*10) + digit;
            temp/=10;
        }
        return (reverse == x);
    }
};
