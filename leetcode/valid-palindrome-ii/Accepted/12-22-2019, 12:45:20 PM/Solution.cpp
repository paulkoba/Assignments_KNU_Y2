// https://leetcode.com/problems/valid-palindrome-ii

bool isPalindrome(const string_view& s) {
    size_t sz = s.size();
    for(size_t i = 0; i < sz / 2; ++i) if (s[i] != s[sz - i - 1]) return false;
    return true;
}

class Solution {
public:
    bool validPalindrome(string s) {
        size_t sz = s.size();
        
        for(size_t i = 0; i < sz / 2; ++i) if (s[i] != s[sz - i - 1]) {
            string_view temp1 = string_view(s.data() + i + 1, sz - 2 * i - 1);
            if(isPalindrome(temp1)) return true;

            string_view temp2 = string_view(s.data() + i, sz - 2 * i - 1);
            if(isPalindrome(temp2)) return true;

            return false;
        }
        
        return true;
    }
};