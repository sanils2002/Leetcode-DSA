//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int counts[n + 1] = {0};
        vector<int> v;
        sort(arr.begin(),arr.end());
        
        for(int i = 0 ; i < n ; i++){
            counts[arr[i]]++;
        }
        
        for(int i = n ; i >= 0 ; i--){
            if(counts[i] == 2){
                v.push_back(i);
                break;
            }
        }
        
        for(int i = n ; i >= 0 ; i--){
            if(counts[i] == 0){
                v.push_back(i);
                break;
            }
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends