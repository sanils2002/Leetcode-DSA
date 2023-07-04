//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int m, int n) {
        // code here
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
        for(int i = m; i <= n; ++i) {
            if(primes[i]) {
                primeNumbers.push_back(i);
            }
        }

        return primeNumbers;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends