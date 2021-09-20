// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n);
        vector<int> cols(m);
        for(size_t i = 0; i < indices.size(); ++i) {
            ++rows[indices[i][0]];
            ++cols[indices[i][1]];
        }
        int odd = 0;
        int even = 0;
        for(size_t i = 0; i < m; ++i) cols[i] % 2 == 0 ? ++even : ++odd;
        int result = 0;
        for(size_t i = 0; i < n; ++i) result += rows[i] % 2 == 0 ? odd : even;
        return result;
    }
};