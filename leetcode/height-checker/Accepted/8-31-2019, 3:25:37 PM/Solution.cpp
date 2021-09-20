// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(const vector<int>& heights) {
        int size = heights.size();
        if(size == 0) return 0;
        vector<int> copy_heights = vector<int>(heights.begin(), heights.end());
        std::sort(copy_heights.begin(), copy_heights.end());
        int out = 0;
        for(int i = 0; i < size; ++i) {
            if(copy_heights[i] != heights[i]) ++out;
        }
        
        return out;
    }
};