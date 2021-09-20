// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        size_t length = points.size();
        double area = numeric_limits<double>::min();
        for(int i = 0; i < length; ++i) {
            for(int j = i + 1; j < length; ++j) {
                for(int k = j + 1; k < length; ++k) {
                    area = max(area, findArea(points[i], points[j], points[k]));
                }
            }
        }
        
        return area;
    }
    
    double findArea(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return 0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1]
                        - a[1] * b[0] - b[1] * c[0] - c[1] * a[0]);
    }
                             
};