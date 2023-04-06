class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, bool& flag) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) {
            flag = false;
            return;
        }
        if(grid[i][j] == 1) 
            return;
        grid[i][j] = 1;
        dfs(grid, i+1, j, flag);
        dfs(grid, i-1, j, flag);
        dfs(grid, i, j+1, flag);
        dfs(grid, i, j-1, flag);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0) {
                    bool flag = true;
                    dfs(grid, i, j, flag);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};