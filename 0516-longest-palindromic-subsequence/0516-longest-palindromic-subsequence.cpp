class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];

        // Initialize dp array with 1s for base cases
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill the dp array for all substrings of length >= 2
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && len == 2) {
                    dp[i][j] = 2;
                }
                else if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }

        // Return the length of the longest palindromic subsequence
        return dp[0][n-1];
    }
};