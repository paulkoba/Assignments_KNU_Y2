// https://leetcode.com/problems/total-hamming-distance

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        size_t sz = nums.size();
        int hamming = 0;
        for(int i = 0; i < 30; ++i) {
            int temp = 0;
            for(int j = 0; j < sz; ++j) temp += (nums[j] >> i) & 1;
            hamming += temp * (sz - temp);
        }
        return hamming;
    }
};