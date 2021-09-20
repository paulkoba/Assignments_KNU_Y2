// https://leetcode.com/problems/slowest-key

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int t0 = 0;
        int ll = 0;
        char out = 'a';
        
        for(int i = 0; i < releaseTimes.size(); ++i) {
            if(releaseTimes[i] - t0 > ll) {
                ll = releaseTimes[i] - t0;
                out = keysPressed[i];
            }
            
            if(releaseTimes[i] - t0 == ll) {
                out = max(keysPressed[i], out);
            }
            
            t0 = releaseTimes[i];
        }
        
        return out;
    }
};