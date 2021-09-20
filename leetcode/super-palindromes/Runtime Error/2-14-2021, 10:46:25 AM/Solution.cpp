// https://leetcode.com/problems/super-palindromes

class Solution {
public:
    bool isPalindrome(int i) {
        int num = i;
        int reverse = 0;
        
        do {
            int digit = i % 10;
            reverse = reverse * 10 + digit;
            i /= 10;
        } while(i != 0);
        
        return reverse == num;
    }
    
    int superpalindromesInRange(string left, string right) {
        uint64_t l = std::stoi(left);
        uint64_t r = std::stoi(right);
        
        int t = std::sqrt(l);
        int out = 0;
        
        for(int i = t; i <= std::sqrt(r); ++i) {
            out += isPalindrome(i) && isPalindrome(i * i);
        }
        
        return out;
    }
};