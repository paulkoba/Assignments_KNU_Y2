// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = -1;
        for(int i = arr.size() - 1; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = greatest;
            greatest = max(temp, greatest);
        }
        return arr;
    }
};