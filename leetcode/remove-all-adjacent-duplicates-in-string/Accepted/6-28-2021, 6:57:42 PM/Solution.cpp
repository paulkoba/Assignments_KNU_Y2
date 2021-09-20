// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> str;
        
        for(char ch : s) {
            if(!str.empty() && str.top() == ch) {
                str.pop();
            } else {
                str.push(ch);
            }
        }
        
        string output;
        
        output.reserve(str.size());
        
        while(!str.empty()) {
            output.append(1, str.top());
            str.pop();
        }
        
        reverse(output.begin(), output.end());
        
        return output;
    }
};