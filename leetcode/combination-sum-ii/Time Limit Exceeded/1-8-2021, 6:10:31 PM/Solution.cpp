// https://leetcode.com/problems/combination-sum-ii

class Solution {
    void combinationSumInner(vector<int>& candidates, set<vector<int>>& output, int target, int idx, vector<int>& current ) {
        if(target == 0) output.insert(current);
        if(idx < 0) return;

        for(int i = idx; i >= 0; --i) {
            current.push_back(candidates[i]);
            combinationSumInner(candidates, output, target - candidates[i], i - 1, current);
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        set<vector<int>> output;
        vector<int> current;
        combinationSumInner(candidates, output, target, candidates.size() - 1, current);
        
        return vector(output.begin(), output.end());
    }
};