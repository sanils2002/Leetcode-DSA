//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n) {
        // code here 
        int low = 0;        // Pointer for 0s
        int mid = 0;        // Pointer for 1s
        int high = n - 1;  // Pointer for 2s
        
        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends