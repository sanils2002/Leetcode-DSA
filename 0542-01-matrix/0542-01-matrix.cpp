class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
    
        vector<vector<int>> distance(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
    
        // Initialize the queue with cells containing 0 and mark their distance as 0
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }
    
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
        while(!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
        
            for(const auto& direction : directions) {
                int newRow = current.first + direction.first;
                int newCol = current.second + direction.second;
            
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && distance[newRow][newCol] == -1) {
                    distance[newRow][newCol] = distance[current.first][current.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    
        return distance;
    }
};