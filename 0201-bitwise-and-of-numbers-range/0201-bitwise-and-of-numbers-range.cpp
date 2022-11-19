class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int idx = 0;
        
        while(left != right) {
            idx++;
            left >>= 1;
            right >>= 1;
        }
        
        return left << idx;
    }
};