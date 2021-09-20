// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> sTransformed;
        vector<char> tTransformed;
        
        for(char s : S) {
            if(s != '#') {
                sTransformed.push_back(s);
            } else {
                if(sTransformed.size() != 0) sTransformed.pop_back();
            }
        }
        
        for(char t : T) {
            if(t != '#') {
                tTransformed.push_back(t);
            } else {
                if(tTransformed.size() != 0) tTransformed.pop_back();
            }
        }
        
        return sTransformed == tTransformed;
    }
};