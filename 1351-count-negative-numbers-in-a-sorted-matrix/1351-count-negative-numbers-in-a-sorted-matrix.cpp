class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Start from the top-right corner
        int row = 0;
        int col = n - 1;

        while(row < m && col >= 0) {
            if(grid[row][col] < 0) {
                // All numbers below this element in the column will also be negative
                count += (m - row);
                col--;
            } 
            else {
                // Move to the next row
                row++;
            }
        }

        return count;
    }
};