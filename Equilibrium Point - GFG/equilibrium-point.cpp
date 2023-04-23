//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(1 == n) {
            return 1;
        }
        //int pre, suf;
        int sum = 0;
        for(int idx = 0 ; idx < n ; idx++) {
            sum += a[idx];
        }
        
        int pre = 0;
        for(int idx = 0 ; idx < n ; idx++) {
            sum -= a[idx];
            if(pre == sum) {
                return idx + 1;
            }
            pre += a[idx];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends