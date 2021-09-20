// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int mSize = 0, count = 0;
        
        for(const auto& rect : rectangles) {
            if(min(rect[0], rect[1]) > mSize) {
                mSize = min(rect[0], rect[1]);
                count = 1;
            } else if(min(rect[0], rect[1]) == mSize) {
                ++count;
            }
        }
        
        return count;
    }
};