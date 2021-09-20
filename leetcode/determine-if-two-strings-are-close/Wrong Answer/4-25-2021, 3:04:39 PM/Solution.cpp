// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        char counts[26] = {};
        
        if(word1.size() != word2.size()) return false;
        
        for(int i = 0; i < word1.size(); ++i) {
            ++counts[word1[i] - 'a'];
            --counts[word2[i] - 'a'];
        }
        
        
        
        for(int i = 0; i < 26; ++i) {
            if(counts[i]) return false;
        }
        
        return true;
    }
};