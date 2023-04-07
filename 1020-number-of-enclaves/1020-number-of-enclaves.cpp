class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = true;
        if(i > 0 && grid[i - 1][j] && !visited[i - 1][j]) {
            dfs(i - 1, j, grid, visited);
        }
        if(j > 0 && grid[i][j - 1] && !visited[i][j - 1]) {
            dfs(i, j - 1, grid, visited);
        }
        if(i < m - 1 && grid[i + 1][j] && !visited[i + 1][j]) {
            dfs(i + 1, j, grid, visited);
        }
        if(j < n - 1 && grid[i][j + 1] && !visited[i][j + 1]) {
            dfs(i, j + 1, grid, visited);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        dfs(i, j, grid, visited);
                    }
                }
            }
        }
    
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    count++;
                }
            }
        }
    
        return count;
    }
};