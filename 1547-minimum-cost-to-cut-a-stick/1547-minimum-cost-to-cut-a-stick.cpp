class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the start and end points to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end()); // Sort the cuts array

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Perform bottom-up dynamic programming
        for(int len = 2; len < m; ++len) {
            for(int i = 0; i < m - len; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
    
        return dp[0][m - 1];
    }
};