// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = min(height[l], height[r]) * (r - l);
        while(l < r) {
            if(height[l] > height[r]) {
                --r;
            } else {
                ++l;
            }
            
            maxArea = max(min(height[l], height[r]) * (r - l), maxArea);
        }
        
        return maxArea;
    }
};