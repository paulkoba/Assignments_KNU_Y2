// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return ""; 
        istringstream text(s);
        vector<string> words(istream_iterator<string>{text}, istream_iterator<string>());
        size_t sz = words.size();
        for(size_t i = 0; i < sz; ++i) reverse(words[i].begin(), words[i].end());
        string output;
        for(size_t i = 0; i < sz - 1; ++i) output.append(words[i]).append(" ");
        output.append(words[sz - 1]);
        return output;
    }
};