class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) 
            return 0;
        
        // dp[i][j] = minimum sum of any falling path ending at (i, j)
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Initialize the first row of dp with the values of the first row of matrix
        for(int j = 0; j < n; j++) 
            dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // choose the minimum from three possible choices for
                // next element in falling path
                
                //directly below
                int minPath = dp[i - 1][j];
                
                //diagonally left
                if(j > 0)
                    minPath = min(minPath, dp[i - 1][j - 1]);
                
                //diagonally right
                if(j < n - 1)
                    minPath = min(minPath, dp[i - 1][j + 1]);
                
                dp[i][j] = matrix[i][j] + minPath;
            }
        }
        
        // The minimum sum of any falling path is the minimum value in the last row of dp
        int ans = INT_MAX;
        for(int j = 0; j < n; j++) 
            ans = min(ans, dp[n - 1][j]);
        
        return ans;
    }
};