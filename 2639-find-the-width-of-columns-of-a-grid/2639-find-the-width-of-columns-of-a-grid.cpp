class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> maxColWidths(m, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int num = grid[j][i];
                int length = to_string(num).length();
                maxColWidths[i] = max(maxColWidths[i], length);
            }
        }
        return maxColWidths;
    }
};