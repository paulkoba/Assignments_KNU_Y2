// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const size_t sz = s.size();
        size_t start = -1;
        vector<char> chars(256);
        int m = 0, length = 0;
        for(size_t i = 0; i < sz; ++i) {
            if(chars[s[i]]) {
                char duplicate = s[i];
                while(duplicate != s[++start] && start != i) {
                    chars[s[start]] = false;
                    --length;
                }
                chars[s[start]] = false;
                --length;
            }
            chars[s[i]] = true;
            m = max(m, ++length);
        }
        return m;
    }
};