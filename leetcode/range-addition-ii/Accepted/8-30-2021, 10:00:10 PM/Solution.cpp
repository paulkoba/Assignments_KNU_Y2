// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int lm = m;
        int ln = n;
        
        for(int i = 0; i < ops.size(); ++i) {
            if(ops[i][0] < lm) lm = ops[i][0];
            if(ops[i][1] < ln) ln = ops[i][1];
        }
        
        return lm * ln;
    }
};