class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int max_count = 0;
        int max_row = 0;
        
        for(int i = 0; i < m; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            if(count > max_count) {
                max_count = count;
                max_row = i;
            }
        }
        
        return {max_row, max_count};
    }
};