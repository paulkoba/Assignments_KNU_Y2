// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int out = 0;
        int curr = 0;
        
        for(int i : gain) {
            curr += i;
            out = max(curr, out);
        }
        
        return out;
    }
};