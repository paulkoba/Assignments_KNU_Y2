// https://leetcode.com/problems/24-game

class Solution {
public:
    double op(double a, double b, char op) {
        switch(op) {
            case 0:
                return a + b;
            case 1:
                return a - b;
            case 2:
                return a / b;
            case 3:
                return a * b;
            default:
                return -100000;
        }
    }
    
    bool cmp(double a) {
        return abs(a - 24.) <= 0.000001;
    }
    
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        
        do {
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < 4; ++j) {
                    for(int k = 0; k < 4; ++k) {
                        double r = op(op(op(cards[0],cards[1], i), cards[2], j), cards[3], k);
                        if(cmp(r)) return true;
                    }
                }
            }
        } while(next_permutation(cards.begin(), cards.end()));
            
        return false;
    }
};