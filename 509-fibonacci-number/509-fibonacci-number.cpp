class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, 0);
        if(0 == n or 1 == n)
            return n;
        
        dp[0] = 0, dp[1] = 1;
        for(int idx = 2 ; idx < n + 1 ; idx++) {
            dp[idx] = dp[idx-1] + dp[idx-2];
        }
        
        return dp[n];
    }
};