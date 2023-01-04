class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long int> ugly(n, INT_MAX);
        ugly[0] = 1;
        vector<int> indices(primes.size(), 0);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < primes.size(); j++) {
                ugly[i] = min(ugly[i], primes[j] * ugly[indices[j]]);
            }
            for(int j = 0; j < primes.size(); j++) {
                if(ugly[i] == primes[j] * ugly[indices[j]]) {
                    indices[j]++;
                }
            }
        }
    
        return ugly[n - 1];
    }
};

/*This program first initializes a vector ugly of size n with the maximum possible value of an integer (INT_MAX). It sets the first element of ugly to 1, which is the first super ugly number. It also initializes a vector indices of size primes.size() with all 0s, which will be used to keep track of the current index of each prime number in the ugly array.

The program then enters a loop that runs n - 1 times, since the first element of ugly has already been set to 1. In each iteration of the loop, it finds the minimum of all products of a prime number in primes with an element in ugly and sets that value to the current element of ugly. It then increments the index of any prime number that was used to calculate this minimum value.

Finally, the program returns the n - 1th element of ugly, which is the nth super ugly number.*/