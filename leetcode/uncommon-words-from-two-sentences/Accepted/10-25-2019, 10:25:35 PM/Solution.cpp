// https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss(A);
        string word;
        unordered_map<string, int> seen;
        while(getline(ss, word, ' ')) ++seen[word];
        ss = stringstream(B);
        while(getline(ss, word, ' ')) ++seen[word];
        vector<string> output;
        for(const auto& p : seen) if(p.second == 1) output.push_back(p.first);
        return output;
    }
};