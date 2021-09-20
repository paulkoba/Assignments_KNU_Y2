// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        
        auto output = upper_bound(arr.begin(), arr.end(), target);
        
        return output == arr.end() ? arr[0] : *output;
    }
};