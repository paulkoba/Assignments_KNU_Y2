// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string S) {
        string output = "";
        int currentBalance = 0;
        for(char ch : S) {
            if(ch == '(') {
                if(currentBalance != 0) output.append(1, '(');
                ++currentBalance;
            } else {
                if(currentBalance != 1) output.append(1, ')');
                --currentBalance;
            }
        }
        
        return output;
    }
};