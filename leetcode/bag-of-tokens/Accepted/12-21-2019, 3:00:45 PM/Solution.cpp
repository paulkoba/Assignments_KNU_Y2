// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        const size_t sz = tokens.size();
        if(sz == 0) return 0;
        size_t first = 0, last = sz - 1;
        int points = 0;
        int pointsMax = 0;
        
        while(first <= last) {
            if(P >= tokens[first]) {
                P -= tokens[first];
                ++first;
                ++points;
                pointsMax = max(pointsMax, points);
            } else if(points >= 1){
                P += tokens[last];
                --last;
                --points;
            } else break;
        }
        return pointsMax;
    }
};