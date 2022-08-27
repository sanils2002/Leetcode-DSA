class Solution {
public:
    int arrangeCoins(int n) {
        long st = 0, en = n;
        while(st <= en) {
            long mid = st + (en - st) / 2;
            long curr = mid * (mid + 1) / 2;
            
            if(n == curr)
                return (int)mid;
            else if(curr > n)
                en = mid - 1;
            else
                st = mid + 1;
        }
        
        return (int)en;
    }
};