// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(const string& s) {
        unordered_map<char, int> temp;
        for(char ch : s) ++temp[ch];
        for(int i = 0; i < s.size(); ++i)
            if(temp[s[i]] <= 1) return i;
        return -1;
    }
};