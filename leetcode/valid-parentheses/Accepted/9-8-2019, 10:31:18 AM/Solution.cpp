// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> output;
        
        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                output.push(ch);
            } else {
                if(output.empty()) return false;
                
                char temp = output.top();
                output.pop();
                
                if(ch == ')' && temp == '(') continue;
                if(ch == ']' && temp == '[') continue;
                if(ch == '}' && temp == '{') continue;
                
                return false;
            }
        }
        
        return output.empty();
    }
};