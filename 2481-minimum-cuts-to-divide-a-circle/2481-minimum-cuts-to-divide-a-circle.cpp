class Solution {
public:
    int numberOfCuts(int n) {
        if(1 == n)
            return 0;
        if(n%2)
            return n;
        return n / 2;
    }
};