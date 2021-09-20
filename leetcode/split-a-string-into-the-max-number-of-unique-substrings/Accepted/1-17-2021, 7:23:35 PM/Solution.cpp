// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

class Solution {
    int maxUniqueSplit(string s, unordered_map<string, int>& ways, unordered_set<string>& uniqueString, int pos = 0) {
        int out = 0;
        
        for(int i = pos; i < s.size(); ++i) {
            
            string str = s.substr(pos, i - pos + 1);
            
            if(uniqueString.find(str) == uniqueString.end()) {
                uniqueString.insert(str);
                
                out = max(out, maxUniqueSplit(s, ways, uniqueString, i + 1) + 1);
                
                uniqueString.erase(str);
            }
        }
        
        return out;
    }
    
public:
    int maxUniqueSplit(string s) {
        unordered_map<string, int> ways;
        unordered_set<string> uniqueString;
        return maxUniqueSplit(s, ways, uniqueString);
    }
};