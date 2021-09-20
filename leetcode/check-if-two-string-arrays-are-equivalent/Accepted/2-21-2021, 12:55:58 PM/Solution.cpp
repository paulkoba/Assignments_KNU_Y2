// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1, a2;
        for(const auto& str : word1) a1.append(str);
        for(const auto& str : word2) a2.append(str);
        
        return a1 == a2;
    }
};