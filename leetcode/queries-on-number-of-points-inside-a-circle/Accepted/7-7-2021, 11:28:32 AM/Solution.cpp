// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> output(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            for(int j = 0; j < points.size(); ++j) {
                output[i] += (points[j][0] - queries[i][0]) * (points[j][0] - queries[i][0]) + 
                    (points[j][1] - queries[i][1]) * (points[j][1] - queries[i][1]) <= 
                    queries[i][2] * queries[i][2];
            }
        }
        
        return output;
    }
};