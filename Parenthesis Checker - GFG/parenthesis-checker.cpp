//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string A)
    {
        // Your code here
        stack<char> stk;
        for(char ch : A) {
            if(ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } 
            else {
                if(stk.empty()) {
                    return false; // No matching opening bracket found
                }
                char top = stk.top();
                stk.pop();
                
                if((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                    return false; // Mismatched closing bracket
                }
            }
        }
        
        return stk.empty(); // Return 1 if the stack is empty, 0 otherwise
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends