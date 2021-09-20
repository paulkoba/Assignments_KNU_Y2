// https://leetcode.com/problems/keyboard-row

bool checkTypableRow(const string& letters, const string& word) {
    for(char ch1 : word) {
        bool fine = false;
        for(char ch2 : letters) {
            if(ch1 == ch2) {
                fine = true;
                break;
            }
        }
        if(!fine) return false;        
    }
    return true;
}
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiopQWERTYUIOP";
        string b = "asdfghjklASDFGHJKL";
        string c = "zxcvbnmZXCVBNM";
        vector<string> output;
        for(const string& word : words) if(checkTypableRow(a, word) ||
                                           checkTypableRow(b, word) ||
                                           checkTypableRow(c, word)) output.push_back(word);
        return output;
    }
};