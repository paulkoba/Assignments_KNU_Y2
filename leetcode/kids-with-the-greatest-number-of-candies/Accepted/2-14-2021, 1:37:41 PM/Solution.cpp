// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxEl = *max_element(candies.begin(), candies.end());
        vector<bool> output(candies.size(), 0);
        for(int i = 0; i < candies.size(); ++i) {
            if(candies[i] + extraCandies >= maxEl) output[i] = true;
        }
        
        return output;
    }
};