// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

class Solution {
public:
    int maxLength(vector<string>& arr) {
        uint32_t field = 0;
        
        vector<uint32_t> containsChars(arr.size(), 0);
        
        for(int i = 0; i < arr.size(); ++i) {
            for(char ch : arr[i]) {
                containsChars[i] |= (1 << (ch - 'a'));
            }
        }
        
        int out = 0;
                
        while(field != (2 << (arr.size() - 1))) {
            uint32_t copy = field;
            
            bool correct = true;
            uint32_t used = 0;
            
            while(copy) {
                int pos = __builtin_ffsl(copy) - 1;
                copy ^= (1 << pos);
                
                if((used & containsChars[pos])) {
                    correct = false;
                    break;
                }
                
                used |= containsChars[pos];
            }
            if(correct) out = max(out, __builtin_popcount(used));
            
            ++field;
        }
        
        return out;
    }
};