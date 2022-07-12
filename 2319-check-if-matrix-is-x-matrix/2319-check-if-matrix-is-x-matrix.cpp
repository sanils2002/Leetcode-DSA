class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int nSize = grid.size();
        for(int idx = 0 ; idx < nSize ; idx++) {
            for(int jdx = 0 ; jdx < nSize ; jdx++) {
                if(jdx == idx or nSize - 1 == idx + jdx) {
                    if(0 == grid[idx][jdx])
                        return false;
                }
                else {
                    if(0 != grid[idx][jdx])
                        return false;
                }
            }
        }
        
        return true;
    }
};