// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int max = 0;
        
        sort(satisfaction.begin(), satisfaction.end());
        
        std::vector<int> hint(satisfaction.size(), 0);
        for(int i = 0; i < satisfaction.size(); ++i) hint[i] = i;
        
        int low = 0, high = satisfaction.size() - 1;
        
        auto cmp = [&] (int position, int unused) {
            int res = 0;
            for(int i = position; i < satisfaction.size(); ++i) {
                res += (i - position + 1) * satisfaction[i];
            }
            
            ++position;
            
            for(int i = position; i < satisfaction.size(); ++i) {
                res -= (i - position + 1) * satisfaction[i];
            }
            
            return res < 0;
        };
        auto it = lower_bound(hint.begin(), hint.end(), 0, cmp);
        
        if(it == hint.end()) return 0;
        int result = *it;

        int res = 0;
        for(int i = result; i < satisfaction.size(); ++i) {
            res += (i - result + 1) * satisfaction[i];
        }
        
        return res;
    }
};