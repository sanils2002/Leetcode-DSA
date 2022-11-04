class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //int num = pow(11, rowIndex);
        vector<int> v(rowIndex+1, 0);
        v[0] = 1;
        for(auto idx = 1 ; idx < rowIndex + 1 ; idx++) {
            for(auto jdx = idx ; jdx >= 1 ; jdx--)
                v[jdx] += v[jdx - 1];
        }
        return v;
    }
};