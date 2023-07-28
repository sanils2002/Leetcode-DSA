class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
    
        // dp[i][j] represents the maximum score difference between player 1 and player 2
        // when the game is played on the subarray nums[i..j].
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        // Base case: the difference when only one element is left is equal to the number itself.
        for(int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
    
        // The outer loop represents the length of the subarray being considered.
        for(int len = 2; len <= n; ++len) {
            // The inner loop represents the starting index of the subarray.
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // ending index of the subarray
            
                // The current player can choose either the first or last element of the subarray.
                // After the choice, the next player will choose optimally to minimize the score difference.
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
    
        // If dp[0][n-1] >= 0, it means that player 1 can achieve a score greater than or equal to player 2.
        return dp[0][n - 1] >= 0;
    }
};