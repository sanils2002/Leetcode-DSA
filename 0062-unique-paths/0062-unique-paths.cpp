class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        // Initialize the first row and column with 1
        for(int i = 0; i < m; i++) 
            dp[i][0] = 1;
        for(int j = 0; j < n; j++) 
            dp[0][j] = 1;

        // Fill in the rest of the grid using the recursive formula
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The result is stored in the bottom-right corner of the grid
        return dp[m - 1][n - 1];
    }
};