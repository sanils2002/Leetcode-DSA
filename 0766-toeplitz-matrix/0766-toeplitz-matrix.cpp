class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int r = 0 ; r < matrix.size() ; r++) {
            for(int c = 0 ; c < matrix[0].size() ; c++) {
                if(r > 0 and c > 0 and matrix[r][c] != matrix[r - 1][c - 1])
                    return false;
            }
        }
        return true;
    }
};