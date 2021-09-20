// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), [&](const vector<int>& a, const vector<int>& b) {
            if(a[1] != b[1]) return a[1] > b[1];
            return a[0] > b[0];
        });
        
        vector<int> output;
        
        for(const auto& elem : restaurants) {
            if((!veganFriendly || elem[2]) && elem[3] <= maxPrice && elem[4] <= maxDistance) 
                output.push_back({elem[0]}); 
        }
        
        return output;
    }
};