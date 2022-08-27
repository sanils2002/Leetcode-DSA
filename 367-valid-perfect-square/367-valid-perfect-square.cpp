class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int st = 1, en = num;
        while(st <= en) {
            long long int mid = st + (en - st) / 2;
            long long check = mid * mid;
            if(check == num)
                return true;
            else if(check > num)
                en = mid - 1;
            else 
                st = mid + 1;
        }
        
        return false;
    }
};