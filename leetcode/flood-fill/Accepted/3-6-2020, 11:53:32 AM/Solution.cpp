// https://leetcode.com/problems/flood-fill

void fillNearby(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    if(image[sr][sc] == newColor) return;
    
    image[sr][sc] = newColor;
    
    if(sr > 0 && image[sr - 1][sc] == oldColor) fillNearby(image, sr - 1, sc, newColor, oldColor);
    if(sr < (image.size() - 1) && image[sr + 1][sc] == oldColor) fillNearby(image, sr + 1, sc, newColor, oldColor);
    if(sc > 0 && image[sr][sc - 1] == oldColor) fillNearby(image, sr, sc - 1, newColor, oldColor);
    if(sc < (image[0].size() - 1) && image[sr][sc + 1] == oldColor) fillNearby(image, sr, sc + 1, newColor, oldColor);
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fillNearby(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};