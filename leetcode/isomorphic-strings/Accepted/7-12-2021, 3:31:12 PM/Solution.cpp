// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> charToCharMapping;
        
        for(int i = 0; i < s.size(); ++i) {
            if(charToCharMapping[s[i]] == 0) {
                charToCharMapping[s[i]] = t[i];
            } else {
                if(charToCharMapping[s[i]] != t[i]) return false;
            }
        }
        
        bool occurence[256] = {};
        
        for(const auto& it : charToCharMapping) {
            if(occurence[it.second]) return false;
            occurence[it.second] = true;
        }
        
        return true;
    }
};