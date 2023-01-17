class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if(N == 0) 
            return vector<int>();
        int M = matrix[0].size();
        if(M == 0) 
            return vector<int>();
        vector<int> result;
        int row = 0, column = 0;
        int direction = 1;
        
        while(row < N && column < M) {
            result.push_back(matrix[row][column]);
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_column = column + (direction == 1 ? 1 : -1);
            
            if(new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                if(direction == 1) {
                    row += (column == M - 1 ? 1 : 0);
                    column += (column < M - 1 ? 1 : 0);
                } 
                else {
                    column += (row == N - 1 ? 1 : 0);
                    row += (row < N - 1 ? 1 : 0);
                }
                
                direction = 1 - direction;
            } 
            else {
                row = new_row;
                column = new_column;
            }
        }
            
        return result;
    }
};