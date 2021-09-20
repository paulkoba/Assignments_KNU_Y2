// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> counts;
        for(char ch : s) ++counts[ch];
        
        int centerCharsLeft = k;
        
        for(const auto& p : counts) {
            if(p.second % 2 == 0) continue;
            --centerCharsLeft;
        } 
        
        return centerCharsLeft >= 0 && s.size() >= k;
    }
};