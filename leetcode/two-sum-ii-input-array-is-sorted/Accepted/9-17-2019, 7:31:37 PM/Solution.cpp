// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int indexLow = 0;
        int indexHigh = numbers.size() - 1;
        while(true) {
            if(numbers[indexLow] + numbers[indexHigh] == target) {
                return {indexLow + 1, indexHigh + 1};
            } else if(numbers[indexLow] + numbers[indexHigh] < target) {
                indexLow++;
            } else {
                indexHigh--;
            }
        }
    }
};