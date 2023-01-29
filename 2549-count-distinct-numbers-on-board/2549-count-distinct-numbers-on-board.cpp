class Solution {
public:
    int distinctIntegers(int n) {
//         int cnt = 0;
//         for(int i = 2 ; i <= n ; i++) {
//             if(n % i == 1)
//                 cnt++;
//         }
        
//         return cnt;
        
        if(n == 0 or n == 1)
            return n;
        else
            return n - 1;
    }
};