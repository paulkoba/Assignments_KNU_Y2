// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());
        vector<int> out(a.size());
        auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), out.begin());
        out.resize(it - out.begin());
        return out;
    }
};