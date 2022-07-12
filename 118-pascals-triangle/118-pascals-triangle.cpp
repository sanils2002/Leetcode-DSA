class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sanil;
        
        for(int idx = 0 ; idx < numRows ; idx++) {
            vector<int> v;
            for(int jdx = 0 ; jdx <= idx ; jdx++) {
                if(0 == jdx || idx == jdx) {
                    v.push_back(1);
                }
                else {
                    vector<int> temp = sanil.back();
                    int val32 = temp[jdx-1] + temp[jdx];
                    v.push_back(val32);
                }
            }
            sanil.push_back(v);
        }
        
        return sanil;
    }
};