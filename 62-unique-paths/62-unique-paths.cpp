class Solution {
public:
    int uniquePaths(int m, int n) {
        int pathTot = m + n - 2;
        double fin_val = 1;
        for(int idx = 1 ; idx <= n - 1 ; idx++) {
            fin_val *= (pathTot - (n - 1) + idx);
            fin_val /= idx;
        }
        return (int)fin_val;
    }
};