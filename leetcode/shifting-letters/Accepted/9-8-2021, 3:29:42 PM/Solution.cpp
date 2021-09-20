// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int64_t shift = 0;
        
        for(int i = s.size() - 1; i >= 0; --i) {
            shift += shifts[i];
            s[i] = ((int)s[i] - 'a' + shift) % 26 + 'a';
        }
        
        return s;
    }
};