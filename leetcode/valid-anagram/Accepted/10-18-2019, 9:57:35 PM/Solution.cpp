// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> temp;
        int sz = t.size();
        if(sz != s.size()) return false;
        
        for(int i = 0; i < sz; ++i) {
            temp[s[i]]++;
            temp[t[i]]--;
        }
        
        for(auto& p: temp) if(p.second != 0) return false;
        
        return true;
    }
};