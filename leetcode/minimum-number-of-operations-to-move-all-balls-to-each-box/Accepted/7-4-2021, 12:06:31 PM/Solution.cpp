// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size();
        vector<int> output(sz);
        int count = 0;
        int countRight = 0;
        for(char ch : boxes) count += ch == '1';
        
        for(int i = 1; i < sz; ++i) {
            output[0] += boxes[i] == '1' ? i : 0;
        }
        
        for(int i = 1; i < sz; ++i) {
            if(boxes[i - 1] == '1') {
                ++countRight;
                --count;
            }
            output[i] = output[i - 1];
            output[i] -= count;
            output[i] += countRight;
        }
        
        return output;
    }
};