// https://leetcode.com/problems/rearrange-spaces-between-words

class Solution {
public:
    string reorderSpaces(string text) {
        text.append(1, ' ');
        int count = -1;
        int wordCount = 0;
        char pr = ' ';
        for(char ch : text) {
            if(ch == ' ') ++count;
            if(ch == ' ' && pr != ' ') ++wordCount;
            pr = ch;
        }
        int spaces = wordCount > 1 ? count / (wordCount - 1) : 0;
        
        string output;
        int idx = 0;
        while(text[idx] == ' ') ++idx;

        while(text.size() != 0 && text[text.size() - 1] == ' ') text.pop_back();
        
        for(; idx < text.size(); ++idx) {
            if(text[idx] == ' ' && idx > 0 && text[idx - 1] != ' ') {
                output.append(spaces, ' ');
            }
            if(text[idx] >= 'a' && text[idx] <= 'z') output.append(1, text[idx]);
        }
        
        output.append(count - spaces * (wordCount - 1), ' ');
        
        return output;
    }
};