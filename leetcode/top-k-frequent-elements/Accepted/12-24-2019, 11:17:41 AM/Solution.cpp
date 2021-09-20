// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_to_freq;
        for(int i : nums) ++nums_to_freq[i];
        vector<pair<int, int>> freq_to_nums(nums_to_freq.size());
        int idx = 0;
        for(const auto& p : nums_to_freq) freq_to_nums[idx++] = make_pair(p.second, p.first);
        sort(freq_to_nums.begin(), freq_to_nums.end(), greater<pair<int, int>>());
        vector<int> output(k);
        for(int i = 0; i < k; ++i) output[i] = freq_to_nums[i].second;
        return output;
    }
};