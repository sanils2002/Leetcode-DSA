class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, priority_queue<int, vector<int>, greater<int>>> diag;
        
        for(int idx = 0 ; idx < m ; idx++){
            for(int jdx = 0 ; jdx < n; jdx++){
                diag[idx - jdx].push(mat[idx][jdx]);
            }
        }
        for(int idx = 0 ; idx < m ; idx++){
            for(int jdx = 0 ; jdx < n ; jdx++){
                mat[idx][jdx] = diag[idx - jdx].top();
                diag[idx - jdx].pop();
            }
        }
        
        return mat;
    }
};