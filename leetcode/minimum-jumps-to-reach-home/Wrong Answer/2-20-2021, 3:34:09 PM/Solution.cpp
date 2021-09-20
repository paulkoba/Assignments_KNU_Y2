// https://leetcode.com/problems/minimum-jumps-to-reach-home

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> visitedFw;
        unordered_set<int> visitedBw;
        int turns = 0;
        
        sort(forbidden.begin(), forbidden.end());
        
        vector<pair<int, bool>> toVisit;
        toVisit.push_back({0, true});
        while(!toVisit.empty()) {
            vector<pair<int, bool>> toVisitTemp;
            for(const auto& pos : toVisit) {
                if(binary_search(forbidden.begin(), forbidden.end(), pos.first)) continue;
                if(pos.first == x) return turns;
                if(visitedFw.find(pos.first) != visitedFw.end()) continue;
                if(!pos.second && visitedBw.find(pos.first) != visitedBw.end()) continue;
                
                if(pos.second && pos.first - b > 0) {
                    toVisitTemp.push_back({pos.first - b, false});
                }
                
                toVisitTemp.push_back({pos.first + a, true});
                
                if(pos.second) {
                    visitedFw.insert(pos.first);
                } else {
                    visitedBw.insert(pos.first);
                }
                
                if(pos.first > 1000000) return -1;
            }
            toVisit = toVisitTemp;
            
            ++turns;
        }
        
        return -1;
    }
};