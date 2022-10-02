class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int sm = INT_MIN;
        for(int idx = 0 ; idx < grid.size() - 2 ; idx++) {
            for(int jdx = 0 ; jdx < grid[0].size() - 2 ; jdx++) {
                int x = grid[idx][jdx] + grid[idx][jdx + 1] + grid[idx][jdx + 2] + grid[idx + 1][jdx + 1] + grid[idx + 2][jdx] + grid[idx + 2][jdx + 1] + grid[idx + 2][jdx + 2];
                sm = max(sm, x);
            }
        }
        return sm;
    }
};