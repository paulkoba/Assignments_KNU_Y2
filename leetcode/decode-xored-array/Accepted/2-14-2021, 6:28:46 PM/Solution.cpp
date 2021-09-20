// https://leetcode.com/problems/decode-xored-array

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        encoded[0] ^= first;
        for(int i = 1; i < encoded.size(); ++i) {
            encoded[i] ^= encoded[i - 1];
        }
        
        encoded.push_back(0);
        
        for(int i = encoded.size() - 1; i > 0; --i)
            encoded[i] = encoded[i - 1];
        
        encoded[0] = first;
         
        return encoded;
    }
};