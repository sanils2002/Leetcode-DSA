class Solution {
public:
    int smallestRangeII(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n-1]-arr[0];

        for(int i = 0 ; i < n - 1 ; i++) {
            int mn = min(arr[0] + k, arr[i + 1] - k);
            int mx = max(arr[n - 1] - k, arr[i] + k);
            ans = min(mx - mn, ans);
        }

        return ans;
    }
};