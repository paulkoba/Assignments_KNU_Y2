// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string str) {
        bool sorted[256] = {};
        int sz = order.size();
        
        for(int i = 0; i < sz; ++i) {
            sorted[order[i]] = i;    
        }
        
        auto cmp = [&](char a, char b) {
            return sorted[a] < sorted[b];
        };
        
        sort(str.begin(), str.end(), cmp);
        
        return str;
    }
};