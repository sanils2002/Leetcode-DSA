class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long int> ugly(n, INT_MAX);
    ugly[0] = 1;
    vector<int> indices(primes.size(), 0);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < primes.size(); j++) {
            ugly[i] = min(ugly[i], primes[j] * ugly[indices[j]]);
        }
        for (int j = 0; j < primes.size(); j++) {
            if (ugly[i] == primes[j] * ugly[indices[j]]) {
                indices[j]++;
            }
        }
    }
    return ugly[n - 1];
    }
};