class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        
        for(int idx = 6 ; idx >= 2 ; idx--) {
            while(n > 6 and 0 == n % idx)
                n /= idx;
        }
        
        return n <= 6; 
    }
};