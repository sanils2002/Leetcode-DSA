class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[10001][101];
        memset(dp, 0, sizeof(dp));
        int move = 0;
        while(dp[move][k] < n) {
            move += 1;
            for(int idx = 1 ; idx <= k ; idx++) {
                dp[move][idx] = dp[move-1][idx-1] + dp[move-1][idx] + 1;
            }
        }
        return move;
    }
};