class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(9, 0);
        dp[0] = 1;
        dp[1] = 10;
        int sum = 1;
        //f(n) = f(0) + f(1) + ... + f(n-1)*(10-n+1)
        for(int idx = 2 ; idx <= n ; idx++) {
            dp[idx] = sum + (10 - idx + 1) * dp[idx-1];
            sum += dp[idx - 1];
        }
        
        return dp[n];
    }
};