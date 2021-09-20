// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDst = 0;
        int currentDst = 0;
        int i = 0;
        
        for(i = 0; i < seats.size(); ++i) {
            if(seats[i] == 1) {
                maxDst = i;
                break;
            }
        }
        
        for(; i < seats.size(); ++i) {
            if(seats[i] == 1) {
                maxDst = max(maxDst, (currentDst + 1) / 2);
                currentDst = 0;
            } else {
                ++currentDst;
            }
        }
        
        maxDst = max(maxDst, currentDst);
        
        return maxDst;
    }
};