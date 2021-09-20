// https://leetcode.com/problems/k-closest-points-to-origin

bool smallerVec(const vector<int>& a, const vector<int>& b) {
    return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), smallerVec);
        return vector(points.begin(), points.begin() + K);
    }
};