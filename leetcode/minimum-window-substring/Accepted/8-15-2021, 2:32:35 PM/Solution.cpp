// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cc(256);
        for(char ch : t) ++cc[ch];    

        auto check = [&]() -> bool {
            for(int i = 0; i < 256; ++i) 
                if(cc[i] > 0) return false;
            
            return true;
        };
        
        auto getCount = [&]() -> int {
            int out = t.size();
            for(int i : cc) out -= i;
            
            return out;
        };

        int count = numeric_limits<int>::max();
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            while(end < s.size() && !check()) {
                --cc[s[end++]];
            }
            if(!check()) break;
            int c = getCount();
            if(count > c) {
                count = c;
                start = i;
            }
            ++cc[s[i]];
        }
        
        if(count == numeric_limits<int>::max()) return "";
        
        return s.substr(start, count);
    }
};