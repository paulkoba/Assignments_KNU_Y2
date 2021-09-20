// https://leetcode.com/problems/redundant-connection

class Solution {    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector<int> parents(n);
        for(int i = 0; i < n; ++i) parents[i] = i;

        function<int(int)> findSet = [&](int a) {
            if(parents[a] != a) return parents[a] = findSet(parents[a]);
            
            return a;
        };
        
        for(const auto& p : edges) {
            if(findSet(p[1]) == findSet(p[0])) return p;
            
            parents[findSet(p[1])] = p[0];
        }
        
        return {};
    }
};