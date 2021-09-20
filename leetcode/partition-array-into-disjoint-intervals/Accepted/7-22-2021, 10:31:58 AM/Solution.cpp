// https://leetcode.com/problems/partition-array-into-disjoint-intervals

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        multiset<int> dd;
        int sz = nums.size();
        nums.push_back(numeric_limits<int>::max());
        for(int i : nums) dd.insert(i);
        int m = nums[0];
        for(int i = 0; i < sz; ++i) {
            if(m <= *dd.begin()) return max(i, 1);
            m = max(nums[i], m);
            dd.erase(dd.find(nums[i]));
        }
        
        return -1;
    }
};