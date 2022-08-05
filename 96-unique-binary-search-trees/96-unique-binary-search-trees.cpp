class Solution {
public:
    int numTrees(int n) { //nth Catalan Number
        if(n <= 1)
            return 1;
        
        vector<int> res(n+1);
        res[0] = res[1] = 1;
        for(int idx = 2 ; idx <= n ; idx++) {
            res[idx] = 0;
            for(int jdx = 0 ; jdx < idx ; jdx++)
                res[idx] += res[jdx] * res[idx - jdx - 1];
        }
        
        return res[n];
    }
};