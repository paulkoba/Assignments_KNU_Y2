// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        
        for(char ch : s)
            if(ch == '1') 
                ++ones;
        
        int maxScore = 0;
        
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == '0') {
                ++zeros;
            } else {
                --ones;
            }
            
            maxScore = max(maxScore, ones + zeros);
        }
        
        return maxScore;
    }
};