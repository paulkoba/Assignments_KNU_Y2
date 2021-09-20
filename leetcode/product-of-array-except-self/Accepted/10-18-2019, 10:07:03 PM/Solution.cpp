// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> upto(sz);
        vector<int> downto(sz);
        upto[0] = nums[0];
        downto[sz - 1] = nums[sz - 1];
        for(int i = 1; i < sz; ++i) {
            upto[i] = upto[i - 1] * nums[i];
            downto[sz - i - 1] = downto[sz - i] * nums[sz - i - 1];
        }
        vector<int> output(sz);
        for(int i = 1; i < sz - 1; ++i) {
            output[i] = upto[i - 1] * downto[i + 1];
        }
        
        output[0] = downto[1];
        output[sz - 1] = upto[sz - 2];
        
        return output;
    }
};