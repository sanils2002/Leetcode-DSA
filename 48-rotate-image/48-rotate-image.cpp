class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int idx = 0 ; idx < matrix.size() ; idx++) {
            for(int jdx = 0 ; jdx < idx ; jdx++)
                swap(matrix[idx][jdx], matrix[jdx][idx]);
        }
        
        for(int idx = 0 ; idx < matrix.size() ; idx++) {
            reverse(matrix[idx].begin(), matrix[idx].end());
        }
        
        //return matrix;
    }
};