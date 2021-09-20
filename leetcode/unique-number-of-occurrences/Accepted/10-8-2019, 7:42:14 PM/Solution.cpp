// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(const vector<int>& arr) {
        unordered_map<int, int> numOccur;
        int size = arr.size();
        
        for(int i = 0; i < size; ++i) {
            if(numOccur.find(arr[i]) != numOccur.end()) {
                ++numOccur[arr[i]];
            } else {
                numOccur[arr[i]] = 1;
            } 
        }
        
        unordered_map<int, int> uniqueNum;
        
        for(const pair<int, int>& a : numOccur) {
            if(uniqueNum.find(a.second) != uniqueNum.end()) {
                return false;
            } else {
                uniqueNum[a.second] = 0;
            }
        }
        
        return true;
    }
};