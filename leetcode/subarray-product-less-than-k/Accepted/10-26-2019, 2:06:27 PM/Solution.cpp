// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
        int first = 0, last = 0, product = 1;
        int out = 0;
        while(last < nums.size()) {
            product *= nums[last];
            while(product >= k && first <= last) product /= nums[first++];
            out += last - first + 1;
            ++last;
        }
        return out;
    }
};