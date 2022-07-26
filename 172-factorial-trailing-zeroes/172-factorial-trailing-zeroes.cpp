class Solution {
public:
    int trailingZeroes(int n) {
        int fac_zero = 0;
        for(int idx = 5 ; n / idx >= 1 ; idx*= 5)
            fac_zero += n / idx;
        return fac_zero;
    }
};