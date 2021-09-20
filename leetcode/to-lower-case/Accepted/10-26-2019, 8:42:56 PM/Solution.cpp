// https://leetcode.com/problems/to-lower-case

class Solution {
public:
    string toLowerCase(string str) {
        for(char& ch : str) if(ch >= 'A' && ch <= 'Z') ch += - 'A' + 'a';
        return str;
    }
};