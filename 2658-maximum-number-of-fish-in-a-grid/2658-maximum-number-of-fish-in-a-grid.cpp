class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int fish = grid[r][c];
        grid[r][c] = 0;  // mark as visited
        int max_fish = fish;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                max_fish += dfs(grid, nr, nc);
            }
        }
    
        return max_fish;
}
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int max_fish = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] > 0) {
                    max_fish = max(max_fish, dfs(grid, r, c));
                }
            }
        }
        return max_fish;
    }
};