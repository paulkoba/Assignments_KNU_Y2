// https://leetcode.com/problems/decode-xored-permutation

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        
        vector<int> hashupto(encoded.size(), 0);
        hashupto[0] = encoded[0];
        for(int i = 1; i < encoded.size(); ++i) hashupto[i] = encoded[i] ^ hashupto[i - 1];
        
        int xor1 = 0;
        for(int i = 0; i < encoded.size(); ++i) xor1 ^= hashupto[i];
        for(int i = 1; i <= encoded.size() + 1; ++i) xor1 ^= i;
        
        encoded[0] ^= xor1;
        
        for(int i = 1; i < encoded.size(); ++i) encoded[i] ^= encoded[i - 1];
        
        encoded.insert(encoded.begin(), xor1);
        
        return encoded;
    }
};