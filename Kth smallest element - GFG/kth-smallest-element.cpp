//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int partition(int arr[], int l, int r) {
        int pivot = arr[r];
        int i = l - 1;
        
        for(int j = l; j < r; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        if(k > 0 && k <= r - l + 1) {
            int partitionIndex = partition(arr, l, r);
            
            if(partitionIndex - l == k - 1) {
                return arr[partitionIndex];
            }
            
            if(partitionIndex - l > k - 1) {
                return kthSmallest(arr, l, partitionIndex - 1, k);
            }
            
            return kthSmallest(arr, partitionIndex + 1, r, k - partitionIndex + l - 1);
        }
        
        // Return a large value if k is out of range
        return INT_MAX;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends