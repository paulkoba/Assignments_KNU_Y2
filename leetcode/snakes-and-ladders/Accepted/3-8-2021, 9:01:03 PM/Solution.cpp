// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        bool flag = true;
        vector<int> linearBoard;
        for(auto j = board.rbegin(); j != board.rend(); ++j) {
            auto i = *j;
            if(flag) {
                 linearBoard.insert(linearBoard.end(), i.begin(), i.end());
            } else {
                 linearBoard.insert(linearBoard.end(), i.rbegin(), i.rend());
            }
            flag = !flag;
        }
                
        vector<int> dp(linearBoard.size(), numeric_limits<int>::max() / 2);
        dp[0] = 0;
        
        for(int i = 0; i < dp.size(); ++i) {
            for(int j = 0; j < dp.size(); ++j) {
                for(int k = 1; k <= 6; ++k) {
                    if(j + k >= dp.size()) break;
                    if(linearBoard[j + k] != -1) {
                        dp[linearBoard[j + k] - 1] = min(dp[j] + 1, dp[linearBoard[j + k] - 1]);
                    } else {
                        dp[j + k] = min(dp[j + k], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[dp.size() - 1] > numeric_limits<int>::max() / 3 ? -1 : dp[dp.size() - 1];
    }
};