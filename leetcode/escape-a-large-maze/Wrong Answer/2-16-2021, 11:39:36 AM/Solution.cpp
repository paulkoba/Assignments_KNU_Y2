// https://leetcode.com/problems/escape-a-large-maze

class Solution {
      
    struct vhash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    
    void dfs(vector<vector<int>>& blocked, vector<int> source, vector<int>& target, unordered_set<vector<int>, vhash>& visited, int& output) {
        if(output > 4901) return;
        if(source[0] < 0 || source[0] > 999999 || source[1] < 0 || source[1] > 999999) return;
        if(visited.find(source) != visited.end()) return;
        if(binary_search(blocked.begin(), blocked.end(), source)) return;
        if(source == target) {
            output = 100500;
            return;
        }
        
        visited.insert(source);
        ++output;
        
        dfs(blocked, {source[0] + 1, source[1]}, target, visited, output);
        dfs(blocked, {source[0] - 1, source[1]}, target, visited, output);
        dfs(blocked, {source[0], source[1] - 1}, target, visited, output);
        dfs(blocked, {source[0], source[1] + 1}, target, visited, output);
    }
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<vector<int>, vhash> visited;
        sort(blocked.begin(), blocked.end());
        int output = 0;
        dfs(blocked, source, target, visited, output);
        unordered_set<vector<int>, vhash> visited2;
        int output2 = 0;
        dfs(blocked, target, source, visited2, output2);
        return output > 4901 && output2 > 4901;
    }
};