// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int limit = 1001;
        
        if(nums.size() == 3) return nums[0] * nums[1] * nums[2];
        
        int min[2] = { limit, limit };
        int max[3] = { -limit, -limit, -limit };
        
        for(int i : nums) {
            if(i < min[0]) {
                min[1] = min[0];
                min[0] = i;
            } else if(i < min[1]) {
                min[1] = i;
            }
            if(i > max[0]) {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = i;
            } else if(i > max[1]) {
                max[2] = max[1];
                max[1] = i;
            } else if(i > max[2]) {
                max[2] = i;
            }
        }
        
        return std::max(min[0] * min[1] * max[0], max[0] * max[1] * max[2]);
    }
};