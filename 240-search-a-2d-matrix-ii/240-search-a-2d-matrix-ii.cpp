class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int l = 0, h = column - 1;
        while(l < row and h >= 0) {
            if(target == matrix[l][h]) {
                return true;
            }
            else if(target > matrix[l][h]) {
                l++;
            }
            else {
                h--;
            }
        }
        
        return false;
    }
};