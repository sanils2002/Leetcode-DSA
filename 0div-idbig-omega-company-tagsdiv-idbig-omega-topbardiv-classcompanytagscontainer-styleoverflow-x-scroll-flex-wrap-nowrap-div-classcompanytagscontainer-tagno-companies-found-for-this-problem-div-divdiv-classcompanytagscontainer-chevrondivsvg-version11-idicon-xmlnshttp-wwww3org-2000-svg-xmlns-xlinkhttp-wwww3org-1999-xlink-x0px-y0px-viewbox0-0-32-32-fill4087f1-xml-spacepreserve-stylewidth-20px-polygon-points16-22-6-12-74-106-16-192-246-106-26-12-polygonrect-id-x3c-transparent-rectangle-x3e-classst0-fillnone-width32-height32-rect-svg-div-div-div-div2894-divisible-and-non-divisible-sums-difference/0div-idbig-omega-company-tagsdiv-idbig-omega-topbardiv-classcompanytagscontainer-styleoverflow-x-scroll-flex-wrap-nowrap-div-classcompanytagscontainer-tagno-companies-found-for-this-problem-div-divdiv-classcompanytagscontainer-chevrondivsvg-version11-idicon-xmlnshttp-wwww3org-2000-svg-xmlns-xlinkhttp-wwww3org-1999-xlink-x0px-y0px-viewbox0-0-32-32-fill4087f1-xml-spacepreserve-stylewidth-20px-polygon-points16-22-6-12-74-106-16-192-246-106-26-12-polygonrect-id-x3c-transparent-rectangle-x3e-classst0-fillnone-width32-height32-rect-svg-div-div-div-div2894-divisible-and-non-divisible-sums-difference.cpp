class Solution {
public:
    int differenceOfSums(int n, int m) {
        int s = n * (n + 1) / 2;
        int a = n / m;
        a = a * (a + 1) * m / 2;
        
        return s - a - a;
    }
};