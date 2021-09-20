// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for(const string& str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            
            map[sorted].push_back(str);
        }
        
        vector<vector<string>> output;
        
        for(const auto& p : map) {
            output.push_back(p.second);
        }
        
        return output;
    }
};