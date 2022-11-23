class Solution {
public:
     bool isValidSudoku(vector<vector<char>>& board) {
        int r[9][10] = {0}, c[9][10] = {0}, b[9][10] = {0};
        for(int idx = 0 ; idx < 9 ; idx++){
            for(int jdx = 0 ; jdx < 9 ; jdx++){
                if('.' == board[idx][jdx])
                    continue;
                int n = board[idx][jdx] - '0';
                if(r[idx][n]++ or c[jdx][n]++ or b[(idx / 3) * 3 + jdx / 3][n]++)
                    return 0;
            }
        }
        return 1;
    }
};