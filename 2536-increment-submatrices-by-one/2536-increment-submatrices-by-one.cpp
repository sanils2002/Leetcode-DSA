class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(auto query : queries) {
            int row1 = query[0], col1 = query[1], row2 = query[2], col2 = query[3];
            mat[row1][col1] += 1;
            if(row2 + 1 < n && col2 + 1 < n) 
                mat[row2 + 1][col2 + 1] += 1;
            if(row2 + 1 < n) 
                mat[row2 + 1][col1] -= 1;
            if(col2 + 1 < n) 
                mat[row1][col2 + 1] -= 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) 
                mat[i][j] += mat[i][j - 1];
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) 
                mat[i][j] += mat[i - 1][j];
        }
    
        return mat;
    }
};