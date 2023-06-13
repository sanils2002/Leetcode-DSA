class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
    
        //Count occurrences of each row in the grid
        map<vector<int>, int> rowCounts;
        for(int i = 0; i < n; i++) {
            rowCounts[grid[i]]++;
        }
    
        // Check for equal row-column pairs
        for(int j = 0; j < n; j++) {
            vector<int> col;
            for(int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            count += rowCounts[col];
        }
    
        return count;
    }
};