class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first cell
        dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

        // Initialize the first row and column
        for(int i = 1; i < m; i++) {
            dp[i][0] = (grid[i][0] == 0) ? dp[i - 1][0] : 0;
        }
        for(int j = 1; j < n; j++) {
            dp[0][j] = (grid[0][j] == 0) ? dp[0][j - 1] : 0;
        }

        // Fill the rest of the cells
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};