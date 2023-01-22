class Solution {
public:
    int alternateDigitSum(int n) {
//         int sum = 0;
//         int sign = 1; // start with positive sign for most significant digit
//         while(n > 0) {
//             int digit = n % 10;
//             sum += sign * digit;
//             sign = -sign; // flip sign for next digit
//             n /= 10;
//         }
    
//         return sum;
        
        string s = to_string(n);
        int ans1 = 0, ans2 = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            if(i%2 == 0)
                ans1 += (s[i] - '0');
            else
                ans2 += (s[i] - '0');
        }
        
        return ans1 - ans2;
    }
};