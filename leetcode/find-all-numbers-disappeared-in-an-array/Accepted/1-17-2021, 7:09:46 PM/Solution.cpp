// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(int i : nums) seen.insert(i);
        
        vector<int> output;
        
        for(int i = 1; i <= nums.size(); ++i) {
            if(seen.find(i) == seen.end()) output.push_back(i);
        }
        
        return output;
    }
};