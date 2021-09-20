// https://leetcode.com/problems/decode-string

pair<std::string, size_t> decodeSubstring(const string& s, size_t i) {
    string output;
    int count = 0;
    while(s[++i] != ']') {
        if(s[i] <= '9' && s[i] >= '0') {
                count = count * 10 + s[i] - '0';
            } else if(s[i] == '[') {
                auto t = decodeSubstring(s, i);
                i = t.second;
                for(int i = 0; i < count; ++i) output.append(t.first);
                count = 0;
            } else {
                output.push_back(s[i]);
        }
    }
    return make_pair(output, i);
}

class Solution {
public:
    string decodeString(const string& s) {
        size_t l = s.size();
        string output;
        int count = 0;
        for(int i = 0; i < l; ++i) {
            if(s[i] <= '9' && s[i] >= '0') {
                count = count * 10 + s[i] - '0';
            } else if(s[i] == '[') {
                auto t = decodeSubstring(s, i);
                i = t.second;
                for(int i = 0; i < count; ++i) output.append(t.first);
                count = 0;
            } else {
                output.push_back(s[i]);
            }
        }
        return output;
    }
};