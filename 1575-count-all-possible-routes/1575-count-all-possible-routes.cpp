class Solution {
const int MOD = 1e9 + 7;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));

        // Initialize the base cases
        dp[start][fuel] = 1;

        // Dynamic programming
        for(int f = fuel; f >= 0; f--) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i != j) {
                        int cost = abs(locations[i] - locations[j]);
                        if(f >= cost) {
                            dp[i][f - cost] = (dp[i][f - cost] + dp[j][f]) % MOD;
                        }
                    }
                }
            }
        }

        int routes = 0;
        for(int f = 0; f <= fuel; f++) {
            routes = (routes + dp[finish][f]) % MOD;
        }

        return routes;
    }
};