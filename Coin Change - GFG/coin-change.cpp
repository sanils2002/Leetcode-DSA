//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        // code here.
        // Create a dp array to store the number of ways to make each sum from 0 to 'sum'
        vector<long long int> dp(sum + 1, 0);
        
        // There is 1 way to make a sum of 0 (by not selecting any coin)
        dp[0] = 1;
        
        // Iterate over the coins
        for(int i = 0; i < N; i++) {
            // Iterate over all possible sums from 'coins[i]' to 'sum'
            for(int j = coins[i]; j <= sum; j++) {
                // Add the number of ways to make the remaining sum (j - coins[i])
                dp[j] += dp[j - coins[i]];
            }
        }
        
        // The number of ways to make the required sum is stored at dp[sum]
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends