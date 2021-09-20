// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int start = 0, end = piles.size() - 1;
        int output = 0;
        while(start <= end) {
            ++start;
            output += piles[end - 1];
            end -= 2;
        }
        
        return output;
    }
};