// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> out(num + 1);
        for(int i = 0; i < num + 1; ++i)
        {
            int t = i;
            int count = 0;
            while(t != 0) {
                t &= t - 1;
                ++count;
            }
            out[i] = count;
        }
        return out;
    }
};