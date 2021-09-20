// https://leetcode.com/problems/reverse-only-letters

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string strLetters;
        for(auto it = s.rbegin(); it != s.rend(); ++it) {
            if(isalpha(*it)) strLetters.push_back(*it);
        }
        
        auto it = strLetters.begin();
        
        for(char& ch : s) {
            if(isalpha(ch)) ch = *it++;
        }
        
        return s;
    }
};