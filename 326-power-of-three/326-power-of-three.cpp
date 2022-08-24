class Solution {
public:
    bool isPowerOfThree(int n) {
        if(0 >= n)
            return false;
        if(1 == n)
            return true;
        if(n%3)
            return false;
        
        return isPowerOfThree(n/3);
    }
};