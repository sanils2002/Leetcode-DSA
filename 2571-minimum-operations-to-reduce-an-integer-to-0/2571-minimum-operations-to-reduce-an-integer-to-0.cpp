class Solution {
public:
    int minOperations(int n) {
        if(n == 0)
            return 0;
        
        int x = floor(1.0 * log2(n));
        int y = ceil(1.0 * log2(n));
        if(abs(pow(2, x) - n) > abs(pow(2, y) - n))
            return 1 + minOperations((abs(pow(2, y) - n)));
        else
            return 1 + minOperations((abs(pow(2, x) - n)));
    }
};