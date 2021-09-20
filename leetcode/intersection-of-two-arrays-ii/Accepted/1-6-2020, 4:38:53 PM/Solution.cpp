// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> output(nums1.size() + nums2.size());
        auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), output.begin());
        output.resize(it - output.begin());
        return output;
    }
};