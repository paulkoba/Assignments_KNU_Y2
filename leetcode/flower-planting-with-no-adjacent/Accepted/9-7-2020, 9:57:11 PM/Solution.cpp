// https://leetcode.com/problems/flower-planting-with-no-adjacent

class Solution {
private:
    bool backtrack(vector<int>& color, vector<vector<int>>& paths, int N, int k) {
        if(k == N) return true;
            
        //Pre-select which types N-th garden can possibly be of.
        bool temp[5] = {0, 1, 1, 1, 1}; //First value is dummy.
        for(int dest : paths[k]) temp[color[dest]] = 0;

        for(int i = 1; i < 5; ++i) {
            //Skip if one of neighbors if already of such type.
            if(temp[i] != 1) continue;
            
            color[k] = i;
            
            if(backtrack(color, paths, N, k + 1)) return true;
        }
        
        return false;
    }
    
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> color(N, 0);
        
        vector<vector<int>> paths_transformed(N);
        for(auto& vec : paths) {
            paths_transformed[vec[0] - 1].push_back(vec[1] - 1);
            paths_transformed[vec[1] - 1].push_back(vec[0] - 1);
        }
        
        backtrack(color, paths_transformed, N, 0);
        
        return color;
    }
};