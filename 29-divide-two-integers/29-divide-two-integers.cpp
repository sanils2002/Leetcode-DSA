class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==-2147483648 and divisor==-1) 
            return 2147483647;
        if(dividend==-2147483648 and divisor==1) 
            return -2147483648; 
        if(dividend<=-2147483648) 
            return -2147483648/divisor; 
        
        int fin_val = dividend / divisor;
        return fin_val;
        
    }
};