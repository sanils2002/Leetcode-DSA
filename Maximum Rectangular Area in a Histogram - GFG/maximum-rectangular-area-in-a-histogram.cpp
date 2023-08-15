//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    long long max(long long a, long long b) {
        return a > b ? a : b;
    }
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        // Add a sentinel value at the end of the vector to handle the case where
        // the last element is the highest.
        vector<long long> heights;
        for(int i = 0 ; i < n ; i++) {
            heights.push_back(arr[i]);
        }
        
        heights.push_back(0);

        stack<long long> stack;
        long long max_area = 0;
        for(int i = 0; i < heights.size(); ++i) {
            // Keep removing elements from the stack until we find an element
            // that is smaller than the current one or the stack is empty.
            
            while(!stack.empty() && heights[stack.top()] > heights[i]) {
                long long height = heights[stack.top()];
                stack.pop();
                
                // Calculate the area for the rectangle formed by the popped element.
                // The width of the rectangle is the distance between the current
                // position and the start of the rectangle.
                
                int width = stack.empty() ? i : i - stack.top() - 1;
                max_area = max(max_area, width * height);
            }
            // Push the current element onto the stack.
            stack.push(i);
        }
        
        return max_area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends