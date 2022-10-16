class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int idx = 0 ; idx <= num ; idx++) {
            int n = idx;
            int rev = 0;
            while(n) {
                rev = rev * 10 + (n % 10);
                n /= 10;
            }
            if(num == rev + idx)
                return true;
        }
        return false;
    }
};