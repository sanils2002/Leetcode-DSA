class Solution {
public:
    bool helper(long long n, int target) {
        int sum = 0;
        while(n) {
            sum += (n%10);
            n /= 10;
        }
        return sum <= target;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long sum = 0, x = 10;
        
        while(true) {
            if(helper(n, target)) {
                return sum;
            }
            else {
                long long val = x - (n%x);
                n += val;
                sum += val;
                x *= 10;
            }
        }
        return sum;
    }
};