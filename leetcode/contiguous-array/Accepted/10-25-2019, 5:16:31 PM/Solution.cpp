// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int sz = nums.size();
        unordered_map<int, int> a; //Balance and index
        int currentBalance = 0;
        for(int i = 0; i < sz; ++i) {
            currentBalance += nums[i] * 2 - 1;
            if(currentBalance == 0) maxLength = i + 1;
            if(a.find(currentBalance) == a.end()) {
                a[currentBalance] = i;
            } else {
                maxLength = max(maxLength, i - a[currentBalance]);
            }
        }
        return maxLength;
    }
};