// https://leetcode.com/problems/alphabet-board-path

class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        
        string output;
        
        for(char ch : target) {
            int targetX = (ch - 'a') % 5;
            int targetY = (ch - 'a') / 5;
            
            for(; x < targetX; ++x) output += 'R';
            for(; x > targetX; --x) output += 'L';
            
            for(; y < targetY; ++y) output += 'D';
            for(; y > targetY; --y) output += 'U';
            output += '!';
        }
        
        return output;
    }
};