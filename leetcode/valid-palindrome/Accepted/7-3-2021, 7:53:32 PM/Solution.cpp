// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char ch : s) {
            if(ch >= 'a' && ch <= 'z') str.append(1, ch);
            if(ch >= '0' && ch <= '9') str.append(1, ch);
            if(ch >= 'A' && ch <= 'Z') str.append(1, ch - 'A' + 'a');
        }
        string cp = str;
        reverse(str.begin(), str.end());
        return str == cp;
    }
};