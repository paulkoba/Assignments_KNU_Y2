// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        size_t sz = coordinates.size();
        if(sz <= 2) return true;
        const double k = double(coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]); //y = kx + b
        const double b = coordinates[0][1] - coordinates[0][0] * k;
        for(size_t i = 2; i < sz; ++i) if(coordinates[i][1] - coordinates[i][0] * k != b) return false;
        return true;
    }
};