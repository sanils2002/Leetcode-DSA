class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int i, int j, int num_visited) {
    int n = grid.size();
    if (num_visited == n * n) {
        return true;
    }
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != num_visited) {
        return false;
    }
    vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto [di, dj] : moves) {
        if (dfs(grid, i + di, j + dj, num_visited + 1)) {
            return true;
        }
    }
    return false;
}
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, 0, 0, 0);
    }
};