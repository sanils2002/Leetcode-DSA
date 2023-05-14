class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<int> prv(n, 0);
        for(int j = 1; j < m; j++) {
            vector<int> nxt(n, INT_MIN);
            for(int i = 0; i < n; i++) {
                if(grid[i][j] > grid[i][j-1]) {
                    nxt[i] = max(nxt[i], prv[i]+1);
                }
            }

            for(int i = 1; i < n; i++) {
                if(i - 1 >= 0 && grid[i][j] > grid[i-1][j-1]) {
                    nxt[i] = max(nxt[i], prv[i-1]+1);
                }
            }

            for(int i = n - 2; i >= 0; i--) {
                if(i + 1 < n && grid[i][j] > grid[i+1][j-1]) {
                    nxt[i] = max(nxt[i], prv[i+1]+1);
                }
            }

            res = max(res, *max_element(nxt.begin(), nxt.end()));
            prv = nxt;
        }

        return res;
    }
};