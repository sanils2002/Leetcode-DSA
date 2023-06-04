class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> dp(n, vector<int> (2));
        long long val = 0;
        
        for(int i = 0 ; i < n ; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        
        int cr = 0, cc = 0;
        for(int i = queries.size() - 1 ; i >= 0 ; i--) {
            if(dp[queries[i][1]][queries[i][0]]) {
                queries[i][0] == 0 ? cr++ : cc++;
                val += (n - (queries[i][0] == 0 ? cc : cr)) * queries[i][2];
                dp[queries[i][1]][queries[i][0]] = 0;
            }
        }
        
        return val;
    }
};