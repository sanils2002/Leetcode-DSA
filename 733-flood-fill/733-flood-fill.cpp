class Solution {
private:
    void dFS(vector<vector<int>>& image, int r, int c, int color_n, int color) {
        if (color_n == image[r][c]) {
            image[r][c] = color;
            if (r >= 1) 
                dFS(image, r-1, c, color_n, color);
            if (c >= 1) 
                dFS(image, r, c-1, color_n, color);
            if (r+1 < image.size()) 
                dFS(image, r+1, c, color_n, color);
            if (c+1 < image[0].size()) 
                dFS(image, r, c+1, color_n, color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int color_n = image[sr][sc];
        if(color != color_n)
            dFS(image, sr, sc, color_n, color);
        return image;
    }
};