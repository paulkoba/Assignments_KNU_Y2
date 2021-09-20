// https://leetcode.com/problems/combination-sum-ii

class Solution {
    void combinationSumInner(vector<int>& candidates, vector<vector<int>>& output, int target, int idx, vector<int>& current ) {
        if(target == 0) output.push_back(current);
        if(target < 0) return;
        
        for(int i = idx; i < candidates.size(); ++i) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            
            current.push_back(candidates[i]);
            combinationSumInner(candidates, output, target - candidates[i], i + 1, current);
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> output;
        vector<int> current;
        combinationSumInner(candidates, output, target, 0, current);
        
        return output;
    }
};