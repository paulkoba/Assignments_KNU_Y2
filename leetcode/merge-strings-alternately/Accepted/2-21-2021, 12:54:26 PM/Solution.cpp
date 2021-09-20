// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out;
        int ptr = 0;
        for(; ptr < word1.size() && ptr < word2.size(); ++ptr) {
            out.append(1, word1[ptr]);
            out.append(1, word2[ptr]);
        }
        
        while(ptr < word1.size()) out.append(1, word1[ptr++]);
        while(ptr < word2.size()) out.append(1, word2[ptr++]);
        
        return out;
    }
};