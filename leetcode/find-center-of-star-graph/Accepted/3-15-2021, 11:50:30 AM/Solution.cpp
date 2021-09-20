// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> count;
        
        for(int i = 0; i < 2; ++i) {
            ++count[edges[i][0]];
            ++count[edges[i][1]];
        }
        
        for(const auto& i : count) {
            if(i.second > 1) return i.first;
        }
        
        return -1;
    }
};