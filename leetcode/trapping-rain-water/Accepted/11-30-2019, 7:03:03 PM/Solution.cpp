// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        vector<int> trappableLeft(sz);
        vector<int> trappableRight(sz);
        for(int i = 1; i < sz; ++i) {
            trappableLeft[i] = max(trappableLeft[i - 1], height[i - 1]);
            trappableRight[sz - i - 1] = max(trappableRight[sz - i], height[sz - i]);
        }
        int volume = 0;
        
        for(int i = 0; i < sz; ++i) {
            volume += max(0, min(trappableRight[i], trappableLeft[i]) - height[i]);
        }
        
        return volume;
    }
};