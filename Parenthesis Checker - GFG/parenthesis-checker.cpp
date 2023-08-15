//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char> st;
        st.push(s[0]);
        
        for(int idx = 1 ; idx < s.size() ; idx++) {
            if(s[idx] == ')' && !st.empty() && st.top() == '(' ) 
                st.pop();
            else if(s[idx] == '}' && !st.empty() && st.top() == '{' ) 
                st.pop();
            else if(s[idx] == ']' && !st.empty() && st.top() == '[' ) 
                st.pop();
            else 
                st.push(s[idx]);
        }
        
        return st.empty();
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