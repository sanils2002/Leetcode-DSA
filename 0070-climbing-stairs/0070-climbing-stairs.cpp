class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        vector<int>dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int idx = 2 ; idx < n ; idx++) {
            dp[idx] = dp[idx-1] + dp[idx-2];
        }
        return dp[n-1];
    }
};