// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                unordered_map<char, int> count;
                for(int m = 0; m < 3; ++m) {
                    for(int n = 0; n < 3; ++n) {
                        count[board[3 * i + m][3 * j + n]]++;
                    }
                }
                
                for(const auto& p : count) if(p.second >= 2 && p.first != '.') return false;
            }
        }

        for(int i = 0; i < 9; ++i) {
            unordered_map<char, int> count;
            unordered_map<char, int> count2;

            for(int j = 0; j < 9; ++j) {
                count[board[i][j]]++;
                count2[board[j][i]]++;
            }
            
            for(const auto& p : count) if(p.second >= 2 && p.first != '.') return false;
            for(const auto& p : count2) if(p.second >= 2 && p.first != '.') return false;
        }
        
        return true;
    }
};