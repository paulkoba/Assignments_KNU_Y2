// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    vector<uint16_t> rows;
    vector<uint16_t> cols;
    vector<uint16_t> quads;
    
    bool solve(vector<vector<char>>& board, vector<vector<char>>& out, int i, int j) {
        if(j == 9) {
            return solve(board, out, i + 1, 0);
        }
        
        if(i == 9) return true;
        
        if(board[i][j] != '.') return solve(board, out, i, j + 1);

        for(int ii = 0; ii < 9; ++ii) {
            if(rows[i] & (1 << ii)) continue;
            if(cols[j] & (1 << ii)) continue;
            if(quads[i / 3 + (j / 3 * 3)] & (1 << ii)) continue;
            
            rows[i] |= (1 << ii);
            cols[j] |= (1 << ii);
            quads[i / 3 + (j / 3 * 3)] |= (1 << ii);
            
            out[i][j] = '1' + ii;
            bool result = solve(board, out, i, j + 1);
            
            rows[i] ^= (1 << ii);
            cols[j] ^= (1 << ii);
            quads[i / 3 + (j / 3 * 3)] ^= (1 << ii);
            
            if(result) return true;
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> out = board;
        rows = vector<uint16_t>(9);
        cols = vector<uint16_t>(9);
        quads = vector<uint16_t>(9);
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                
                rows[i] |= 1 << (board[i][j] - '1');
                cols[j] |= 1 << (board[i][j] - '1');
                quads[i / 3 + (j / 3 * 3)] |= 1 << (board[i][j] - '1');
            }
        }

        solve(board, out, 0, 0);
        
        board = out;
    }
};