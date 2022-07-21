class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> matr(column, vector<int> (row, 0));
        for(int idx = 0 ; idx < row ; idx++) {
            for(int jdx = 0 ; jdx < column ; jdx++) {
                matr[jdx][idx] = matrix[idx][jdx];
            }
        }
        return matr;
    }
};