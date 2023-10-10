//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        int n = s.length();
        vector<string> temp;
        string sCopy="";
        
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '.') {
                temp.push_back(sCopy);
                temp.push_back(".");
                sCopy = "";
            }
            else {
                sCopy += s[i];
            }
        }
        temp.push_back(sCopy);
        
        
        reverse(temp.begin(), temp.end());
        string ans = "";
        for(int i = 0 ; i < temp.size() ; i++) {
            ans += temp[i];
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends