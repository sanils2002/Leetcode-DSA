class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m == 0) return result;
        int n = matrix[0].size();
        if(n == 0) return result;

        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;

        while(startRow <= endRow && startCol <= endCol) {
            for(int i = startCol; i <= endCol; i++) {
                result.push_back(matrix[startRow][i]);
            }
            startRow++;

            for(int i = startRow; i <= endRow; i++) {
                result.push_back(matrix[i][endCol]);
            }
            endCol--;

            if(startRow <= endRow) {
                for(int i = endCol; i >= startCol; i--) {
                    result.push_back(matrix[endRow][i]);
                }
                endRow--;
            }

            if(startCol <= endCol) {
                for(int i = endRow; i >= startRow; i--) {
                    result.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }

        return result;
    }
};