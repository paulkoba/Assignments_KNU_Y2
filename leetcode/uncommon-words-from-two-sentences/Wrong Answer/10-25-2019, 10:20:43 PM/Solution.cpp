// https://leetcode.com/problems/uncommon-words-from-two-sentences

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss(A);
        string word;
        set<string> seenA, seenB;
        while(getline(ss, word, ' ')) {
            seenA.insert(word);
        }
        ss = stringstream(B);
        vector<string> output;
        while(getline(ss, word, ' ')) {
            seenB.insert(word);
        }
        vector<string> a;
        set_symmetric_difference(seenA.begin(), seenA.end(), seenB.begin(), seenB.end(), back_inserter(a));
        return a;
    }
};