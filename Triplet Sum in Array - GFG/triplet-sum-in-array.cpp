//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        //Your Code Here
        long long closestSum = 0;
        long long minDiff = LLONG_MAX;
        sort(nums, nums + n);
        
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];
                long long diff = abs(sum - X);
                
                if(diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
                
                if(sum < X) left++;
                else right--;
            }
        }
        
        return closestSum == X;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends