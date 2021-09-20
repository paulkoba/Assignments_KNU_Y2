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
                        double r1 = op(op(op(cards[0], cards[1], i), cards[2], j), cards[3], k);
                        double r2 = op(op(cards[0], cards[1], i), op(cards[2], cards[3], j), k);
                        double r3 = op(cards[0], op(cards[1], op(cards[2], cards[3], i), j), k);
                        double r4 = op(cards[0], op(op(cards[1], cards[2], i), cards[3], j), k);
                        double r5 = op(op(cards[0], op(cards[1], cards[2], i), j), cards[3], k);

                        if(cmp(r1) || cmp(r2) || cmp(r3) || cmp(r4) || cmp(r5)) return true;
                    }
                }
            }
        } while(next_permutation(cards.begin(), cards.end()));
            
        return false;
    }
};