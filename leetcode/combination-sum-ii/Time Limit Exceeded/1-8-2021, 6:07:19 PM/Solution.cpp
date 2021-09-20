// https://leetcode.com/problems/combination-sum-ii

class Solution {
    void combinationSumInner(vector<int>& candidates, set<vector<int>>& output, int target, int idx, vector<int> current ) {
        if(target == 0) output.insert(current);
        if(idx < 0) return;

        for(int i = idx; i >= 0; --i) {
            vector temp(current.begin(), current.end());
            temp.push_back(candidates[i]);
            combinationSumInner(candidates, output, target - candidates[i], i - 1, temp);
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        set<vector<int>> output;
        
        combinationSumInner(candidates, output, target, candidates.size() - 1, {});
        
        return vector(output.begin(), output.end());
    }
};