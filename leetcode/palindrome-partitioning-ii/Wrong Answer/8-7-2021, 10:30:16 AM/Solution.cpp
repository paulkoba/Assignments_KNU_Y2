// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(const string& s) {
        int n = s.size();
        vector<int> count(n + 1, 0);
        
        for(int i = 0; i < n + 1; ++i) count[i] = i - 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) {
                count[i + j + 1] = min(count[i + j + 1], count[i - j] + 1);
            }
            
            for(int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + 1]; ++j) {
                count[i + j + 1] = min(count[i + j + 1], count[i - j + 1] + 1);
            }
        }
        return count[n];
    }
};