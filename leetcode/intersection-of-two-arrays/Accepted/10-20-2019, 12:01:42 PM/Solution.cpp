// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, char> t1;
        for(int a: nums1) t1[a] = 1;
        unordered_map<int, char> t2;
        for(int a: nums2) t2[a] = 1;
        vector<int> output;
        auto f = t1.end();
        for(const pair<int,char>& p : t2) if(t1.find(p.first) != f) output.push_back(p.first);
        return output;
    }
};