class Solution {
private:
    int factors(int n) {
        long long int sum = 0;
        for (int i = 2; n > 1; i++) {
            while (n % i == 0) {
                sum += i;
                n /= i;
            }
        }
        
        return sum;
    }
public:
    int smallestValue(int n) {
        while(n !=factors(n)) {
            n =factors(n);
        }
        
        return n;
    }
};