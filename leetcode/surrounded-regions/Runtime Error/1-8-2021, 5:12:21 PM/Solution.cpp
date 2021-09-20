// https://leetcode.com/problems/surrounded-regions

class Solution {
private:
    void recursiveMark(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board[0].size()) return;
        
        if(board[i][j] == 'X') return;
        if(board[i][j] == 'M') return;
        
        board[i][j] = 'M';
        recursiveMark(board, i + 1, j);
        recursiveMark(board, i - 1, j);
        recursiveMark(board, i, j + 1);
        recursiveMark(board, i, j - 1);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            recursiveMark(board, i, 0);
            recursiveMark(board, i, board[0].size() - 1);
        }
        
        
        for(int i = 0; i < board[0].size(); ++i) {
            recursiveMark(board, 0, i);
            recursiveMark(board, board.size() - 1, i);
        }
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
};