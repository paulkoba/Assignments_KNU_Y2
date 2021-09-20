// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        multiset<int> dd;
        for(int i : nums) dd.insert(i);
        int sz = nums.size();
        int m = nums[0];
        for(int i = 0; i < sz; ++i) {
            if(m < *dd.begin()) return i;
            m = max(nums[i], m);
            dd.erase(dd.find(nums[i]));
        }
        
        return -1;
    }
};