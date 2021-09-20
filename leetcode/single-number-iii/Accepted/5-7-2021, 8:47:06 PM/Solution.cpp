// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, total = 0;
        for(int i : nums) total ^= i;
        
        int l = -1;
        
        while(!(total & (1 << (++l))));
        
        for(int i : nums) {
            if(i & (1 << l)) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        
        return {x1, x2};
    }
};