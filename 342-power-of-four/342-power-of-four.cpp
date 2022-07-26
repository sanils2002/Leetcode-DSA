class Solution {
public:
    bool isPowerOfFour(int n) {
        if(0 == n)
            return false;
        else if(1 == n)
            return true;
        else if(0 == n % 4)
            return isPowerOfFour(n / 4);
        else 
            return false;
        
    }
};