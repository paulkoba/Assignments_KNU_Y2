// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> occ;
        size_t sz = arr.size();
        for(size_t i = 0; i < sz; ++i) ++occ[arr[i]];
        vector<int> a(occ.size());
        size_t i = 0;
        for(const auto& p : occ) a[i++] = p.second;
        sort(a.begin(), a.end());
        size_t removed = 0;
        sz /= 2;
        while(removed < sz) removed += a[--i];
        return occ.size() - i;
    }
};