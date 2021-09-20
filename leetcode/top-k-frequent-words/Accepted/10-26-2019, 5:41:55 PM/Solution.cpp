// https://leetcode.com/problems/top-k-frequent-words

bool compare(const pair<int, string>& i, const pair<int, string>& j)
{
    if(i.first > j.first) return false;
    if(i.first < j.first) return true;
    return i.second > j.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for(const string& str : words) ++count[str];
        vector<pair<int, string>> reverseCount(count.size());
        int i = 0;
        for(const auto& p : count) reverseCount[i++] = make_pair(p.second, p.first);
        sort(reverseCount.begin(), reverseCount.end(), compare);
        vector<string> common(k);
        for(int j = 0; j < k; ++j) common[j] = reverseCount[i - j - 1].second;
        return common;
    }
};