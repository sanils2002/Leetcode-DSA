//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xxor = 0;
        for(auto it : nums) {
            xxor ^= it;
        }
        
        int mask = (xxor & -xxor);
        int set = 0, unset = 0;
        for(auto it : nums) {
            if(it & mask)
             set ^= it;
            else
             unset ^= it;
        }
        
        if(set > unset) swap(set,unset);
        return {set, unset};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends