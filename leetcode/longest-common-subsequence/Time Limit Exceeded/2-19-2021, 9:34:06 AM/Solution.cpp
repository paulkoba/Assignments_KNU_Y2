// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string text1, string text2, int m, int n) {
        if(m == 0 || n == 0) return 0;
        if(text1[m - 1] == text2[n - 1]) return 1 + lcs(text1, text2, m - 1, n - 1);
        
        return max(lcs(text1, text2, m - 1, n), lcs(text1, text2, m, n - 1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.size(), text2.size());
    }
};