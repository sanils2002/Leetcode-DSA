class Solution {
private:
    int ans = 1e9;
    void solve(vector<vector<int>> &grid , int idx , int cnt , int n , int m){
        if(idx >= 9) {
            int flag = 1;
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++)  {
                    if(grid[i][j] != 1) 
                        flag = false;
                }
            }
            if(flag) {
                ans = min(ans , cnt);
                return;
            } 
        }
        

        int x = idx / 3 , y = idx % 3;
        if(grid[x][y] == 0) {
            for(int i = 0 ; i < 3 ; i++) {
                for(int j = 0 ; j < 3 ; j++)  {
                    if(grid[i][j] > 1) {
                        grid[i][j] -= 1;
                        grid[x][y] += 1;
                        solve(grid, idx + 1, cnt + abs(x-i) + abs(y-j) , n , m);
                        grid[x][y] -= 1;
                        grid[i][j] += 1;
                    }
                }
            }
        }
        
        else 
            solve(grid, idx + 1, cnt, n, m);
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        solve(grid, 0, 0, 3, 3);
        return ans;
    }
};