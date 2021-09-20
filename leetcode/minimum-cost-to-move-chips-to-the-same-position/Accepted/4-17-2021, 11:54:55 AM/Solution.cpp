// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int mCost = numeric_limits<int>::max();
        
        unordered_map<int, int> positions;
        for(int a : position) ++positions[a];
        
        for(const auto& a : positions) {
            int cost = 0;

            for(const auto& b : positions) {
                cost += b.second * ((((a.first - b.first) % 2) + 2) % 2);
            }
            
            mCost = min(mCost, cost);
        }
        
        return mCost;
    }
};