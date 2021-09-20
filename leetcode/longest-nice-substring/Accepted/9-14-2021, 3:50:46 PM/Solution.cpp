// https://leetcode.com/problems/longest-nice-substring

class Solution {
public:
    string longestNiceSubstring(string s) {
        
        int currentLongest = 0;
        int currentLongestIdx = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            uint64_t a = 0, b = 0;
        
            for(int j = i; j < s.size(); ++j) {
                if(s[j] >= 'a' && s[j] <= 'z') {
                    a |= 1 << (s[j] - 'a');
                } else {
                    b |= 1 << (s[j] - 'A');
                }
                
                if(!(a ^ b)) {
                    if(currentLongest < j - i + 1) {
                        currentLongest = j - i + 1;
                        currentLongestIdx = i;
                    }
                }
            }
        }
        
        return s.substr(currentLongestIdx, currentLongest);
    }
};