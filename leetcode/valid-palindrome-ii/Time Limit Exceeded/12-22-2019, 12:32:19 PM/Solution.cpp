// https://leetcode.com/problems/valid-palindrome-ii

bool isPalindrome(const string& s) {
    size_t sz = s.size();
    for(size_t i = 0; i < sz / 2; ++i) if (s[i] != s[sz - i - 1]) return false;
    return true;
}

class Solution {
public:
    bool validPalindrome(string s) {
        size_t sz = s.size();
        for(size_t i = 0; i < sz / 2; ++i) {
            for(size_t i = 0; i < sz / 2; ++i) if (s[i] != s[sz - i - 1]) {
                string temp1 = s.substr(0, i).append(s.substr(i + 1, sz));
                if(isPalindrome(temp1)) return true;
                
                string temp2 = s.substr(0, sz - i - 1).append(s.substr(sz - i, sz));
                if(isPalindrome(temp2)) return true;
                
                return false;
            }
        }
        return true;
    }
};