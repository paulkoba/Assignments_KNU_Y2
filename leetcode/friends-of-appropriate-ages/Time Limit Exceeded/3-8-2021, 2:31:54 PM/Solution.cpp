// https://leetcode.com/problems/friends-of-appropriate-ages

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int output = 0;
        for(int i = 0; i < ages.size(); ++i) {
            for(int j = 0; j < ages.size(); ++j) {
                output += (i != j) && (2 * ages[j] - 14 > ages[i]) && (ages[j] <= ages[i]) && (ages[j] <= 100 || ages[i] >= 100);
            }
        }
        return output;
    }
};