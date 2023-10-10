//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> specialXor(int N, int Q, int a[], vector<int> query[])
    {
        // code here
        int preXor[N + 1] = {0};
        for(int i = 0 ; i < N ; i++) {
            preXor[i + 1] = preXor[i] ^ a[i];
        }
        
        int finalXor = preXor[N];
        vector<int> res;
        for(int i = 0 ; i < Q ; i++) {
            int low = query[i][0];
            int up = query[i][1];
            int excludedXor = preXor[up] ^ preXor[low - 1];
            res.push_back(finalXor ^ excludedXor);
        }
        
        return res;
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends