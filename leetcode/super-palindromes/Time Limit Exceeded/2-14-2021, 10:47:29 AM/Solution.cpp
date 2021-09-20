// https://leetcode.com/problems/super-palindromes

class Solution {
public:
    bool isPalindrome(uint64_t i) {
        uint64_t num = i;
        uint64_t reverse = 0;
        
        do {
            int digit = i % 10;
            reverse = reverse * 10 + digit;
            i /= 10;
        } while(i != 0);
        
        return reverse == num;
    }
    
    int superpalindromesInRange(string left, string right) {
        uint64_t l = std::stol(left);
        uint64_t r = std::stol(right);
        
        uint64_t t = std::sqrt(l);
        uint64_t out = 0;
        
        for(uint64_t i = t; i <= std::sqrt(r); ++i) {
            out += isPalindrome(i) && isPalindrome(i * i);
        }
        
        return out;
    }
};