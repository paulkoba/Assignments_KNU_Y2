// https://leetcode.com/problems/flood-fill

struct fillData {
    vector<vector<int>>& image;
    int newColor;
    int oldColor;
};

void fillNearby(int sr, int sc, fillData& data) {
    if(data.image[sr][sc] == data.newColor) return;
    
    data.image[sr][sc] = data.newColor;
    
    if(sr > 0 && data.image[sr - 1][sc] == data.oldColor) fillNearby(sr - 1, sc, data);
    if(sr < (data.image.size() - 1) && data.image[sr + 1][sc] == data.oldColor) fillNearby(sr + 1, sc, data);
    if(sc > 0 && data.image[sr][sc - 1] == data.oldColor) fillNearby(sr, sc - 1, data);
    if(sc < (data.image[0].size() - 1) && data.image[sr][sc + 1] == data.oldColor) fillNearby(sr, sc + 1, data);
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fillData data{image, newColor, image[sr][sc]};
        fillNearby(sr, sc, data);
        return image;
    }
};