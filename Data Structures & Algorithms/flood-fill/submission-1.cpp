class Solution {
public:
    void help(vector<vector<int>>& image, int sr, int sc, int val, int color) {
        //super ugly, dont need to manually set all the colors since im doing it at the start. just need to recurse once per side
        image[sr][sc] = color;
        if (sr > 0 && image[sr-1][sc] == val) {
            image[sr-1][sc] = color;
            help(image, sr-1, sc, val, color);
        }
        if (sc > 0 && image[sr][sc-1] == val) {
            image[sr][sc-1] = color; 
            help(image, sr, sc-1, val, color);
        }
        if (sr < image.size()-1 && image[sr+1][sc] == val) {
            image[sr+1][sc] = color;
            help(image, sr+1, sc, val, color);
        }
        if (sc < image[0].size()-1 && image[sr][sc+1] == val) {
            image[sr][sc+1] = color; 
            help(image, sr, sc+1, val, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        if (val == color) return image;
        help(image, sr, sc, val, color);
        return image;
    }
};