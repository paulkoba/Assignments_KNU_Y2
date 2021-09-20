// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size() - 1, i = 0;
        
        while(i < sz) {
            swap(s[i++], s[sz--]);
        }
    }
};