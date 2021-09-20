// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            bool foundC[9] = {};
            bool foundR[9] = {};
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    if(foundC[board[i][j] - '1']) return false;
                    foundC[board[i][j] - '1'] = true;
                }
                
                if(board[j][i] != '.') {
                    if(foundR[board[j][i] - '1']) return false;
                    foundR[board[j][i] - '1'] = true;
                }
            }
        }
        
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                bool found[9] = {};
                for(int k = 0; k < 3; ++k) {
                    for(int l = 0; l < 3; ++l) {
                        if(board[i * 3 + k][j * 3 + l] == '.') continue;
                        if(found[board[i * 3 + k][j * 3 + l] - '1']) return false;
                        found[board[i * 3 + k][j * 3 + l] - '1'] = true;
                    }
                }
            }
        }
        
        return true;
    }
};