class Solution {
private:
    vector<pair<int, int>> bfsQueue;

    // Recursively check the neighboring land cell of current cell grid[x][y] and add all
    // land cells of island A to bfsQueue.
    void dfs(vector<vector<int>>& grid, int x, int y, int n) {
        grid[x][y] = 2;
        bfsQueue.push_back({x, y});
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& dir : directions) {
            int curX = x + dir.first;
            int curY = y + dir.second;
            if (0 <= curX && curX < n && 0 <= curY && curY < n && grid[curX][curY] == 1) {
                dfs(grid, curX, curY, n);
            }
        }
    }

public:
    // Find any land cell, and we treat it as a cell of island A.
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }

        // Add all land cells of island A to bfsQueue.
        bfsQueue.clear();
        dfs(grid, firstX, firstY, n);

        int distance = 0;
        vector<pair<int, int>> newBfs;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!bfsQueue.empty()) {
            newBfs.clear();
            for (const auto& pair : bfsQueue) {
                int x = pair.first;
                int y = pair.second;
                for (const auto& nextPair : directions) {
                    int curX = x + nextPair.first;
                    int curY = y + nextPair.second;
                    if (0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back({curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B, we will
            // start the next round on all water cells that are 1 cell further away from
            // island A and increment the distance by 1.
            bfsQueue = newBfs;
            distance++;
        }

        return distance;
    }
};