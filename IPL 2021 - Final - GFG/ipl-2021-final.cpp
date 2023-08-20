//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> stk;
        stk.push(-1); // Initialize stack with -1 as a starting point

        int maxLength = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                stk.push(i); // Push the index of '(' into the stack
            } 
            else {
                stk.pop(); // Pop the top of the stack (corresponding '(')
                if(stk.empty()) {
                    stk.push(i); // If stack is empty, push the current index as a new starting point
                } 
                else {
                    maxLength = max(maxLength, i - stk.top()); // Calculate the length of the current valid substring
                }
            }
        }
        
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends