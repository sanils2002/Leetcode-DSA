class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            int indexToSort = 1;
            return a[indexToSort] < b[indexToSort];
        });

        vector<int> dp(n, 0);
        int offerIndex = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = (i > 0) ? dp[i - 1] : 0;

            while (offerIndex < offers.size() && offers[offerIndex][1] == i) {
                int start = offers[offerIndex][0];
                int profit = offers[offerIndex][2];
                dp[i] = max(dp[i], (start > 0 ? dp[start - 1] : 0) + profit);
                offerIndex++;
            }
        }

        return dp[n - 1];
    }
};