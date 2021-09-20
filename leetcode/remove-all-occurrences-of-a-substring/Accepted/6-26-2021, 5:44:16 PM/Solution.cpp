// https://leetcode.com/problems/remove-all-occurrences-of-a-substring

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true) {
            auto f = s.find(part);
            if(f == string::npos) return s;
            s.erase(f, part.size());
        }
        
        return s;
    }
};