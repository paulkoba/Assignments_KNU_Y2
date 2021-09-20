// https://leetcode.com/problems/longest-uncommon-subsequence-ii

class Solution {
public:
    bool isSubsequence(string& str1, string& str2, int start, int end) {
        for(int i = 0; start < end && i < str2.size(); ++i) {
            if(str2[i] == str1[start]) ++start;
        }
        
        return start == end;
    }
    
    int findLUSlength(vector<string>& strs) {
        int best = -1;
        for(int i = 0; i < strs.size(); ++i) strs[i].push_back(0);
        for(int i = 0; i < strs.size(); ++i) {
            for(int j = 0; j < strs[i].size(); ++j) {
                for(int k = j + 1; k < strs[i].size(); ++k) {
                    bool flag = false;
                    for(int u = 0; u < strs.size(); ++u) {
                        if(u == i) continue;
                        flag = isSubsequence(strs[i], strs[u], j, k);
                        if(flag) break;
                    }
                    if(!flag) {
                        best = max(best, k - j);
                    }
                }
            }
        }
        return best;
    }
};