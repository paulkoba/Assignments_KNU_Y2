// https://leetcode.com/problems/maximum-xor-for-each-query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int vectXOR = 0;
        for(int i : nums) vectXOR ^= i;
        
        int mask = (1 << maximumBit) - 1;
        
        vector<int> output;
        
        while(nums.size() != 0) {
            int r = nums.back();
            nums.pop_back();
            
            output.push_back((vectXOR & mask) ^ mask);
            vectXOR ^= r;
        }
        
        return output;
    }
};