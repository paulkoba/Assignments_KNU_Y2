// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        size_t sz = word.size();
        if(sz <= 1) return true;
        
        if(word[0] >= 'a') {
            for(size_t i = 1; i < sz; ++i)
                if(word[i] < 'a') return false;
            return true;
        } else if(word[1] >= 'a') {
            for(size_t i = 2; i < sz; ++i)
                if(word[i] < 'a') return false;
            return true;
        } else {
            for(size_t i = 2; i < sz; ++i)
                if(word[i] >= 'a') return false;
            return true;
        }
    }
};