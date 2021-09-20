// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> buff;
        string current = "";
        for(char ch : s) {
            if(ch == ' ') {
                if(current == "") continue;
                
                buff.push_back(current);
                current = "";
            } else {
                current.append(1, ch);
            }
        }
        
        if(current != "") buff.push_back(current);
        
        string output = *(buff.end() - 1);
        
        for(int i = buff.size() - 2; i >= 0; --i) {
            output.append(" ");
            output.append(buff[i]);
        }
        
        return output;
    }
};