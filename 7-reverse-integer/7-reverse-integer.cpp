class Solution {
public:
    int reverse(int x) {
        int rev_val = 0;
        while(x) {
            int temp = x % 10;
            x /= 10;
            if (rev_val > INT_MAX/10 or (rev_val == INT_MAX / 10 and temp> 7)) 
                return 0;
            if (rev_val < INT_MIN/10 or (rev_val == INT_MIN / 10 and temp < -8)) 
                return 0;
            rev_val = rev_val * 10 + temp;
        }
        
        return rev_val;
    }
};