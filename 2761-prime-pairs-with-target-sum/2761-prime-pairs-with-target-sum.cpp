class Solution {
private:
    vector<int> sieveOfEratosthenes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for(int p = 2; p * p <= n; ++p) {
            if(primes[p]) {
                for(int i = p * p; i <= n; i += p) {
                    primes[i] = false;
                }
            }
        }

        vector<int> primeNumbers;
        for(int i = 2; i <= n; ++i) {
            if(primes[i]) {
                primeNumbers.push_back(i);
            }
        }

        return primeNumbers;
    }
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        vector<int> primes = sieveOfEratosthenes(n);

        for(int i = 0; i < primes.size(); ++i) {
            int x = primes[i];
            int y = n - x;
            if(x <= y && binary_search(primes.begin(), primes.end(), y)) {
                result.push_back({x, y});
            }
        }

        return result;
    }
};