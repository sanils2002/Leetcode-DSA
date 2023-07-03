//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
		    vector<int>vec(26,0);
            queue<char>q;
            
            string ans="";
            for(int i=0;i<str.length();i++) {
                char ch=str[i];
                vec[ch-'a']++;
                if(vec[ch-'a']==1)
                    q.push(ch);
                if(q.empty() and vec[ch-'a']==1) ans+=ch;
                else{
                    while(!q.empty() and vec[q.front()-'a']>1) q.pop();
                    if(q.empty()) ans+='#';
                    else ans+=q.front();
                }
            }
            
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends