class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        // dp[diff] represents the maximum height we can achieve with a difference of 'diff' between the two supports
        unordered_map<int, int> dp;
        dp[0] = 0;

        // Iterate through the rods
        for(int i = 0; i < n; i++) {
            // Create a copy of the current dp map to avoid concurrent modification
            unordered_map<int, int> curr(dp);

            // Iterate through the existing differences in dp
            for(const auto& it : curr) {
                int diff = it.first;
                int height = it.second;

                // Case 1: Add the rod to the taller support
                dp[diff + rods[i]] = max(dp[diff + rods[i]], height + rods[i]);

                // Case 2: Add the rod to the shorter support
                dp[diff - rods[i]] = max(dp[diff - rods[i]], height);

                // Case 3: Do not use the rod
                dp[diff] = max(dp[diff], height);
            }
        }

        return dp[0];
    }
};