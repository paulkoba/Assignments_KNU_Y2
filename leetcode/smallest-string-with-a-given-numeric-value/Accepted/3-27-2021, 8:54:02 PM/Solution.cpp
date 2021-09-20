// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    string getSmallestString(int n, int k) {
        string output = string(n, 'a');
        k -= n;
        
        for(int i = n - 1; i >= 0; --i) {
            if(k >= 25) {
                output[i] += 25;
                k -= 25;
            } else {
                output[i] += k;
                break;
            }
        }
        
        return output;
    }
};