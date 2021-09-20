// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distances(n, vector<int>(n, numeric_limits<int>::max() / 2));
        
        for(int i = 0; i < edges.size(); ++i) {
            distances[edges[i][0]][edges[i][1]] = edges[i][2];
            distances[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for(int i = 0; i < n; ++i) {
            distances[i][i] = 0;
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
        
        int index = 0;
        int count = numeric_limits<int>::max();
        
        for(int i = 0; i < n; ++i) {
            int currentCount = 0;
            
            for(int j = 0; j < n; ++j) {
                if(distances[i][j] <= distanceThreshold) ++currentCount;
            }
            
            if(count >= currentCount) {
                count = currentCount;
                index = i;
            }
        }
        
        return index;
    }
};