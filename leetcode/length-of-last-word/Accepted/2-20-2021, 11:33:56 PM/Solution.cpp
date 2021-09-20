// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr = s.size() - 1;
        int count = 0;
        while(ptr >= 0 && s[ptr] == ' ') --ptr;
        while(ptr >= 0 && s[ptr--] != ' ') ++count;
        
        return count;
    }
};