// https://leetcode.com/problems/max-points-on-a-line

struct hasher {
    size_t operator() (const pair<int, int>& a) const {
        return hash<int>()(a.first ^ a.second);
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<pair<int, int>, int, hasher> pts;
        size_t sz = points.size();
        for(size_t i = 1; i < sz; ++i) {
            for(size_t j = 0; j < i; ++j) {
                int k = (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                int a = points[j][1] - k * points[j][0];
                ++pts[make_pair(a, k)];
            }
        }
            
        int m = 0;
        for(const auto& p : pts) m = max(m, p.second);
        return m;
    }
};