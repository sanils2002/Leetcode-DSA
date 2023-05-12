class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0); // dp[i] represents the maximum points that can be earned from questions i to n-1

        for(int i = n-1; i >= 0; i--) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            long long maxPointsIfSolved = points + dp[min(i+brainpower+1, n)]; // maximum points if question i is solved
            long long maxPointsIfSkipped = dp[i+1]; // maximum points if question i is skipped
            dp[i] = max(maxPointsIfSolved, maxPointsIfSkipped);
        }

        return dp[0];
    }
};