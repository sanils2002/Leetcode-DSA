class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        set<int> R, C;
        for(int idx = 0 ; idx < r ; idx++) {
            for (int jdx = 0 ; jdx < c ; jdx++) {
                if(0 == matrix[idx][jdx])
                    R.insert(idx), C.insert(jdx);
            }
        }
        
        for(int idx = 0 ; idx < r ; idx++) {
            for (int jdx = 0 ; jdx < c ; jdx++) {
                if(R.find(idx) != R.end() || C.find(jdx) != C.end())
                    matrix[idx][jdx] = 0;
            }
        }
        
    }
};