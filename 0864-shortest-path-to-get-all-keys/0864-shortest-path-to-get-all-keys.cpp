class Solution {
private:
    struct Point {
    int row;
    int col;
    int keys;
};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numKeys = 0;
        int allKeys = 0;
        int startRow, startCol;

        // Find the starting point and count the number of keys
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                } 
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    numKeys++;
                    allKeys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        queue<Point> q;
        q.push({startRow, startCol, 0});
        visited[startRow][startCol][0] = true;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Point p = q.front();
                q.pop();

                if(p.keys == allKeys)
                    return steps;

                for(auto& dir : dirs) {
                    int newRow = p.row + dir[0];
                    int newCol = p.col + dir[1];
                    int newKeys = p.keys;

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] != '#') {
                        char cell = grid[newRow][newCol];
                        if(cell >= 'A' && cell <= 'F' && !(p.keys & (1 << (cell - 'A'))))
                            continue;

                        if(cell >= 'a' && cell <= 'f')
                            newKeys |= (1 << (cell - 'a'));

                        if(!visited[newRow][newCol][newKeys]) {
                            visited[newRow][newCol][newKeys] = true;
                            q.push({newRow, newCol, newKeys});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};