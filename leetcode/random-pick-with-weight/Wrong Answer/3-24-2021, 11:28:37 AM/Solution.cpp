// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    Solution(vector<int>& w) {
        cumul = vector<int64_t>(w.size());
        cumul[0] = w[0];
        
        for(int i = 1; i < w.size(); ++i) cumul[i] = cumul[i - 1] + w[i];
    }
    
    vector<int64_t> cumul;
    
    int pickIndex() {
        return distance(cumul.begin(), lower_bound(cumul.begin(), cumul.end(), rand() % (*cumul.rbegin())));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */