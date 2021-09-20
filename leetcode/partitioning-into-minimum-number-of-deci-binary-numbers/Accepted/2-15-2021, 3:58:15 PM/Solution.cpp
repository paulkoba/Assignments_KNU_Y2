// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int out = 0;
        for(char ch : n) {
            out = max(ch - '0', out);
        }
        
        return out;
    }
};