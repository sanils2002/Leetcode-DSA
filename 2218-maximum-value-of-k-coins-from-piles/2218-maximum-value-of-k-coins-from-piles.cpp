class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int n = piles.size();
        vector<int> total(n); // total[i] = total value of coins in pile i
        for(int i = 0; i < n; i++) {
            total[i] = accumulate(piles[i].begin(), piles[i].end(), 0);
        }
    
        vector<vector<int>> dp(n + 1, vector<int>(k + 1)); // dp[i][j] = max value you can get from first i piles with j coins
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int curr_total = 0;
                dp[i][j] = dp[i - 1][j]; // case 1: don't take from pile i
                for(int x = 1; x <= piles[i - 1].size(); x++) { // case 2: take x coins from pile i
                    curr_total += piles[i - 1][x - 1];
                    if(j >= x) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + curr_total);
                    }
                }
            }
        }
    
        return dp[n][k];
    }
};