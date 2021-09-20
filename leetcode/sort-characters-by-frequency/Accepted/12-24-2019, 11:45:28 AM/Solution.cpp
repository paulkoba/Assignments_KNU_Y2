// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(const string& s) {
        unordered_map<char, int> char_to_freq;
        for(char ch : s) ++char_to_freq[ch];
        int sz = char_to_freq.size();
        vector<pair<int, char>> freq_to_char(sz);
        for(const auto& p : char_to_freq) 
            freq_to_char[--sz] = make_pair(p.second, p.first);
        sort(freq_to_char.begin(), freq_to_char.end(), greater<pair<int, char>>());
        string output(s.size(), ' ');
        
        for(const auto& p : freq_to_char) {
            for(int i = sz; i < sz + p.first; ++i)
                output[i] = p.second;
            sz += p.first;
        }
        
        return output;
    }
};