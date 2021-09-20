// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int64_t xRev = 0;
        int64_t xCopy = x;
        while(xCopy) {
            xRev *= 10;
            xRev += xCopy % 10;
            xCopy /= 10;
        }

        return xRev == x;
    }
};