// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        char counts1[26] = {};
        char counts2[26] = {};

        if(word1.size() != word2.size()) return false;
        
        for(int i = 0; i < word1.size(); ++i) {
            ++counts1[word1[i] - 'a'];
            ++counts2[word2[i] - 'a'];
        }
        
        sort(counts1, counts1 + 26);
        sort(counts2, counts2 + 26);
        
        for(int i = 0; i < 26; ++i) {
            if(counts1[i] != counts2[i]) return false;
        }
        
        return true;
    }
};