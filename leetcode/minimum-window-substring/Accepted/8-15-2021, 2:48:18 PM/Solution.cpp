// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        vector<int> cc(52);
        for(char ch : t) {
            if(ch >= 'a') {
                cc[26 + ch - 'a']++;
            } else {
                cc[ch - 'A']++;
            }
        }   

        auto check = [&]() -> bool {
            for(int i = 0; i < 52; ++i) 
                if(cc[i] > 0) return false;
            
            return true;
        };
        
        int currentCount = 0;
        int count = numeric_limits<int>::max();
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            bool ccc = false;
            while((ccc = !check()) && end < s.size()) {                
                if(s[end] >= 'a') {
                    cc[26 + s[end] - 'a']--;
                } else {
                    cc[s[end] - 'A']--;
                }
                
                ++end;
                ++currentCount;
            }
            if(ccc) break;
            
            if(count > currentCount) {
                count = currentCount;
                start = i;
            }
            
            if(s[i] >= 'a') {
                cc[26 + s[i] - 'a']++;
            } else {
                cc[s[i] - 'A']++;
            }
            
            --currentCount;
        }
        
        if(count == numeric_limits<int>::max()) return "";
        
        return s.substr(start, count);
    }
};