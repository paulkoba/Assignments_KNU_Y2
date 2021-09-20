// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > 0 && ty > 0) {
            if(sx == tx && sy == ty) return true;
            
            if(tx > ty) {
                int x = tx - ty;
                int y = tx - y;
                
                tx = x;
                ty = y;
            } else {
                int y = ty - tx;
                int x = ty - y;
                
                ty = y;
                tx = x;
            }
        }
        return false;
    }
};