//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        int candidate = 0;
        int count = 0;
        
        // Find the candidate for the majority element
        for(int i = 0; i < size; i++) {
            if(count == 0) {
                candidate = a[i];
                count = 1;
            } 
            else if (a[i] == candidate) {
                count++;
            } 
            else {
                count--;
            }
        }
        
        // Verify if the candidate is indeed the majority element
        count = 0;
        for(int i = 0; i < size; i++) {
            if(a[i] == candidate) {
                count++;
            }
        }
        
        if(count > size / 2) {
            return candidate;
        } 
        else {
            // If no majority element exists, you can return -1 or any other value to indicate that
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends