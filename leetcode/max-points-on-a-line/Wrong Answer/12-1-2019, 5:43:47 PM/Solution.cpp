// https://leetcode.com/problems/max-points-on-a-line

struct hasher {
    size_t operator() (const pair<int, int>& a) const {
        return hash<int>()(a.first ^ a.second);
    }
};

int solveQuad(int temp) { //n(n - 3) / 2 + n = temp.
    return (sqrt(8 * temp + 1) + 1) / 2;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<pair<int, int>, int, hasher> lines;
        unordered_map<int, int> vertical;
        size_t sz = points.size();
        if(sz <= 2) return sz;
        for(size_t i = 1; i < sz; ++i) {
            for(size_t j = 0; j < i; ++j) {
                if(points[j][0] - points[i][0] != 0) {
                    int k = (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    int a = points[j][1] - k * points[j][0];
                    ++lines[make_pair(a, k)];
                } else {
                    ++vertical[points[j][0]];
                }
            }
        }
            
        int m = 0;
        for(const auto& p : lines) m = max(m, solveQuad(p.second));
        for(const auto& p : vertical) m = max(m, solveQuad(p.second));
        return m;
    }
};