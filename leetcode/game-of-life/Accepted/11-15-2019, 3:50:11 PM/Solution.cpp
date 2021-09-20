// https://leetcode.com/problems/game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        
        vector<vector<int>> neighbors(board.size(), vector<int>(board[0].size()));
        
        for(int i = 0; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                neighbors[i][j] += board[i][j - 1];
                neighbors[i][j - 1] += board[i][j];
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                neighbors[i][j] += board[i - 1][j];
                neighbors[i - 1][j] += board[i][j];
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                neighbors[i][j] += board[i - 1][j - 1];
                neighbors[i - 1][j - 1] += board[i][j];
                neighbors[i - 1][j] += board[i][j - 1];
                neighbors[i][j - 1] += board[i - 1][j];
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 0) {
                    board[i][j] = neighbors[i][j] == 3;
                    continue;
                }
                if(neighbors[i][j] < 2) {
                    board[i][j] = 0;
                    continue;
                }
                if(neighbors[i][j] > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};