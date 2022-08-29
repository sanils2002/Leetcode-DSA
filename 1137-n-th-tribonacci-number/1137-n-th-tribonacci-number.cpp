class Solution {
public:
    int tribonacci(int n) {
        if(0 == n)
            return 0;
        if(n > 0 and n <= 2)
            return 1;
        
        vector<int> dp(n+1, 0);
        dp[1] = 1, dp[2] = 1;
        
        for(int idx = 3 ; idx <= n ; idx++) {
            dp[idx] = dp[idx-1] + dp[idx-2] + dp[idx-3];
        }
        
        return dp[n];
    }
};