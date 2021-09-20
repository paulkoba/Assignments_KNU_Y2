// https://leetcode.com/problems/longest-word-in-dictionary

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> occurred = {""};
        string output = "";
        for(const string& word : words) {
            if(occurred.find(word.substr(0, word.size() - 1)) != occurred.end()) {
                occurred.insert(word);
                if(output.size() < word.size()) output = word;
            } 
        }
        
        return output;
    }
};