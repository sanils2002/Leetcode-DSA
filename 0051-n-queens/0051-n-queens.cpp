class Solution {
private:
    bool isValid(vector<int>& pos, int row, int col) {
        for(int i = 0; i < row; i++) {
            if(pos[i] == col || abs(i-row) == abs(pos[i]-col)) {
                // There is already a queen in the same column or diagonal
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> init(n, -1); // Initial state with no queens placed
        q.push(init);
        
        while(!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            
            int row = 0;
            while(row < n && pos[row] != -1) {
                row++;
            }
            if(row == n) {
                // All queens are placed on the board
                vector<string> solution(n, string(n, '.'));
                for(int i = 0; i < n; i++) {
                    solution[i][pos[i]] = 'Q';
                }
                res.push_back(solution);
                continue;
            }
            
            for(int col = 0; col < n; col++) {
                if(isValid(pos, row, col)) {
                    vector<int> new_pos = pos;
                    new_pos[row] = col;
                    q.push(new_pos);
                }
            }
        }
        
        return res;
    }
};