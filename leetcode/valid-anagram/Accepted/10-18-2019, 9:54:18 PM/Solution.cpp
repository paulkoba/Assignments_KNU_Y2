// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> temp;
        for(char ch : s) ++temp[ch];
        for(char ch : t) --temp[ch];
        for(auto& p: temp) if(p.second != 0) return false;
        
        return true;
    }
};