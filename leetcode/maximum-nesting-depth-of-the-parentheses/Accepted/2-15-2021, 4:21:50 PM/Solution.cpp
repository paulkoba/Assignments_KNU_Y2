// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepth = 0;
        
        for(char ch : s) {
            if(ch == '(') {
                ++currentDepth;
                maxDepth = max(maxDepth, currentDepth);
            }
            
            if(ch == ')') {
                --currentDepth;
            }
        }
        
        return maxDepth;
    }
};