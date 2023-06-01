class Solution {
private:
    // Helper function to check if a cell is within the grid boundaries
    bool isValidCell(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // If the start or end cell is blocked, return -1
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        // Direction vectors for 8-directional movement
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Create a queue for BFS
        queue<pair<int, int>> q;
        q.push({0, 0});  // Start from the top-left cell
        grid[0][0] = 1;  // Mark the start cell as visited

        // Perform BFS
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // If we reached the bottom-right cell, return its distance
            if(x == n - 1 && y == n - 1) {
                return grid[x][y];
            }

            // Explore the 8-directional neighbors
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(isValidCell(nx, ny, n) && grid[nx][ny] == 0) {
                    // Mark the neighbor cell as visited and enqueue it
                    q.push({nx, ny});
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
        }

        // If there is no clear path to the bottom-right cell
        return -1;
    }
};