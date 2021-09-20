// https://leetcode.com/problems/total-hamming-distance

class Solution {
public:
    int totalHammingDistance(const vector<int>& nums) {
        int hamming = 0;
        for(int i = 0; i < 30; ++i) {
            int temp = 0;
            for(int j = 0; j < nums.size(); ++j) temp += (nums[j] >> i) & 1;
            hamming += temp * (nums.size() - temp);
        }
        return hamming;
    }
};