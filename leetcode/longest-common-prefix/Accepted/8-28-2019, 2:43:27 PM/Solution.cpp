// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {        
        size_t size_max = std::numeric_limits<size_t>::max();
        size_t vec_length = strs.size();
        if(vec_length == 0) return "";

        for (int i = 0; i < strs.size(); i++)
            size_max = std::min(size_max, strs[i].size());

        for (int i = 0; i < size_max; i++) {
            for (int j = 0; j < vec_length; j++) {
                if (strs[0].at(i) != strs[j].at(i)) return strs[0].substr(0, i);
            }
        }

        return strs[0].substr(0, size_max);
    }
};