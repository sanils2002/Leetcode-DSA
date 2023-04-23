class Solution {
public:
    int sumOfMultiples(int n) {
        int cnt = 0;
        while(n > 0) {
            if(n%7 == 0 or n%5 == 0 or n%3 == 0)
                cnt += n;
            n--;
        }
        return cnt;
    }
};