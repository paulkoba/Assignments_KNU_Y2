// https://leetcode.com/problems/longest-word-in-dictionary

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        set<string> occurred = {""};
        size_t sz = 0;
        for(const string& word : words) {
            if(occurred.find(word.substr(0, word.size() - 1)) != occurred.end()) {
                occurred.insert(word);
                sz = max(sz, word.size());
            } 
        }
        
        for(const string& word : occurred) if(word.size() == sz) return word;
        return "";
    }
};