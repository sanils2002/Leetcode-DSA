//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
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
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends