//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if(n <= 2) {
            return n;
        }
        vector<long long>dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int idx = 2 ; idx < n ; idx++) {
            dp[idx] = (dp[idx-1] + dp[idx-2]) % (1000000007);
        }
        return dp[n-1];
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends