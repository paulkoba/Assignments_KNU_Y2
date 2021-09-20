// https://leetcode.com/problems/max-chunks-to-make-sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currentMax = 0, numChunks = 0;
        for(int i = 0; i < arr.size(); ++i) {
            currentMax = max(currentMax, arr[i]);
            if(currentMax == i) ++numChunks;
        }
        return numChunks;
    }
};