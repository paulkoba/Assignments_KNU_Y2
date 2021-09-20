// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        const size_t sz = hand.size();
        if(sz % W != 0) return false;
        
        unordered_map<int, int> cards;
        for(int i : hand) ++cards[i];
        
        while(cards.size() != 0) {
            auto it = min_element(cards.begin(), cards.end());
            int k = it->first;
            for(int i = 0; i < W; ++i) {
                auto p = cards.find(k + i);
                if(p == cards.end()) return false;
                if(--p->second == 0) cards.erase(p);
            }
        }
        
        return true;
    }
};