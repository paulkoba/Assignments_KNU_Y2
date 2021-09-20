// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        
        vector<vector<int>> output;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                string word = words[i] + words[j];
                bool flag = true;
                for(int k = 0; k < word.size() / 2; ++k) 
                    if(word[k] != word[word.size() - k - 1]) {
                    flag = false;
                    break;
                }
                if(flag) output.push_back({i, j});
            }
        }
        
        return output;
    }
};