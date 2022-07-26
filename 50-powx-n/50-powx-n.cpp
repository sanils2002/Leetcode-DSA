class Solution {
public:
    double myPow(double x, int n) {
        if(0 == n)
            return 1;
        if(1 == n)
            return x;
        if(-1 == n)
            return 1/x;
        
        double y = myPow(x, n / 2);
        if (0 == n % 2) 
            return y * y;
        
        return n > 0 ? y * y * x : y * y * 1 / x;

    }
};