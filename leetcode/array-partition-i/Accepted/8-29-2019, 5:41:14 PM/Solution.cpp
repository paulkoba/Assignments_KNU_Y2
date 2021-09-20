// https://leetcode.com/problems/array-partition-i

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        auto f = nums.end();
        int answer = 0;
        for(auto iter = nums.begin(); iter < f; iter += 2) {
            answer += *iter;
        }
        
        return answer;
    }
};