//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int max_idx = n - 1;
    	int min_idx = 0;
    	int max_element = arr[n - 1] + 1; // Add 1 to ensure it's larger than the max element
    	
    	for(int i = 0; i < n; i++) {
    	    // If 'i' is even, store the maximum element at 'arr[i]'
    	    if(i % 2 == 0) {
    	        arr[i] += (arr[max_idx] % max_element) * max_element;
    	        max_idx--;
    	    }
    	    // If 'i' is odd, store the minimum element at 'arr[i]'
    	    else {
    	        arr[i] += (arr[min_idx] % max_element) * max_element;
    	        min_idx++;
    	    }
    	}
    	
    	// Retrieve original values and update the array
    	for(int i = 0; i < n; i++) {
    	    arr[i] = arr[i] / max_element;
    	}
    	 
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends