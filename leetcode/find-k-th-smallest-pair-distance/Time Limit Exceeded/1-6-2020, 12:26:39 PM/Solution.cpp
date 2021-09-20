// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t sz = nums.size();
        vector<int> positions(sz - 1);
        priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int, size_t>>> smallest;
        for(size_t i = 0; i < sz - 1; ++i) {
            positions[i] = i + 1;
            smallest.push(make_pair(nums[positions[i]] - nums[i], i));
        }
        
        for(int current = 1; current < k; ++current) {
            size_t i = smallest.top().second;
            smallest.pop();
            ++positions[i];
            if(positions[i] < sz)
                smallest.push(make_pair(nums[positions[i]] - nums[i], i));
        }
        
        return smallest.top().first;
    }
};