// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        vector<int> output;
        unordered_set<int> visited = {1};
        for(const auto& t : edges) {
            if(visited.find(t[1]) != visited.end()) {
                output = t;
            } else {
                visited.insert(t[1]);
            }
        }
        return output;
    }
};