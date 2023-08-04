//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arrival[], int departure[], int n)
    {
    	// Your code here
    	sort(arrival, arrival+n);
    	sort(departure, departure+n);
    	
    	int platforms = 0;
    	int currentPlatforms = 0;
    	int i = 0; // index for arrival array
    	int j = 0; // index for departure array
    	
    	while(i < n && j < n) {
    	    if(arrival[i] <= departure[j]) {
    	        // A train is arriving, need an additional platform
    	        currentPlatforms++;
    	        i++;
    	    } 
    	    else {
    	        // A train is departing, release a platform
    	        currentPlatforms--;
    	        j++;
    	    }
    	    
    	    // Update the overall required platforms
    	    platforms = max(platforms, currentPlatforms);
    	}
    	
    	return platforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends