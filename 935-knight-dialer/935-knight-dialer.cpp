class Solution {
public:
    int knightDialer(int n) {
        vector<long> original_dp(10, 1);
        vector<long> dialer_dp(10);
        
        for(int idx = 1 ; idx < n ; idx++) {
            dialer_dp[0] = (original_dp[4] + original_dp[6]) % 1000000007;
            dialer_dp[1] = (original_dp[6] + original_dp[8]) % 1000000007;
            dialer_dp[2] = (original_dp[7] + original_dp[9]) % 1000000007;
            dialer_dp[3] = (original_dp[4] + original_dp[8]) % 1000000007;
            dialer_dp[4] = (original_dp[0] + original_dp[3] + original_dp[9]) % 1000000007;
            dialer_dp[5] = 0 % 1000000007;
            dialer_dp[6] = (original_dp[0] + original_dp[1] + original_dp[7]) % 1000000007;
            dialer_dp[7] = (original_dp[2] + original_dp[6]) % 1000000007;
            dialer_dp[8] = (original_dp[1] + original_dp[3]) % 1000000007;
            dialer_dp[9] = (original_dp[2] + original_dp[4]) % 1000000007;
            
            original_dp = dialer_dp;
        }
        
        return accumulate(original_dp.begin(), original_dp.end(), long(0)) % 1000000007;
        
    }
};