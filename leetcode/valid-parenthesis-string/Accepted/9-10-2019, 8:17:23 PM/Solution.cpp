// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int maxCounter = 0;
        int minCounter = 0;
        
        for(char ch : s) {
            if(ch == '(') {
                maxCounter++;
                minCounter++;
            } else if(ch == ')') {
                minCounter--;
                maxCounter--;
            } else if(ch == '*') {
                maxCounter++;
                minCounter--;
            }
            if(maxCounter < 0) return false;
            minCounter = max(minCounter, 0);
        }
        
        return minCounter == 0;
    }
};