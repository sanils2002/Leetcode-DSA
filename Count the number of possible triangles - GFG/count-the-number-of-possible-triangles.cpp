//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int nums[], int n)
    {
        // code here
        sort(nums, nums + n);
        int trgle = 0;
        
        for(int idx = n - 1 ; idx >= 0 ; idx--) {
            int st = 0, en = idx - 1;
            while(st < en) {
                if(nums[st] + nums[en] > nums[idx])
                    trgle += (en - st), en--;
                else
                    st++;
            }
        }
        
        return trgle;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends