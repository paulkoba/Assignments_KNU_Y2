// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> output;
        
        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                output.push(ch);
            } else {
                if(output.size() == 0) return false;
                switch(ch) {
                    case ']':
                        if(output.top() != '[') return false;
                        output.pop();
                        break;
                        
                    case ')':
                        if(output.top() != '(') return false;
                        output.pop();
                        break;
                        
                    case '}':
                        if(output.top() != '{') return false;
                        output.pop();
                        break;
                        
                    default:
                        break;
                }
            }
        }
        
        return output.size() == 0;
    }
};