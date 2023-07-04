//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) {
        vector<int> v(N), ans;
        v[0] = a[0];
        for(int i = 1 ; i < N ; i++) {
            v[i] = a[i] + v[i - 1];
        }
        
        for(int i = 0 ; i < Q ; i++) {
            int prev = L[i] > 0 ? v[L[i] - 1] : 0;
            int val = v[L[i]] - prev;
            for(int j = L[i] + 1 ; j <= R[i] ; j++) {
                val = max(val, v[j] - prev);
            }
            ans.push_back(val);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n], L[q], R[q];
        
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < q; i++) cin >> L[i] >> R[i];
        Solution obj;
        vector<int> ans = obj.maxPrefixes(a, L, R, n, q);
        for (auto it : ans) 
            cout << it << " ";
        cout << endl;
    }
}

// } Driver Code Ends