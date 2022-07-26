class Solution {
public:
    int mySqrt(int x) {
        long idx = 1;
        while(1 <= x/(idx*idx))
            idx += 1;
        return idx - 1;
    }
};