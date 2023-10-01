class Solution {
private:
    typedef long long ll;
    ll help(vector<int>& v,int idx){
        ll ans = 0;
        int x = v[idx], n = v.size();
        for(int i = idx ; i >= 0 ; i--){
            x = min(x, v[i]);
            ans += x;
        }
        
        x = v[idx];
        for(int i = idx + 1 ; i < n ; i++) {
            x = min(x, v[i]);
            ans += x;
        }
        
        return ans;
    }
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll ans = 0;
        int n = maxHeights.size();
        for(int i = 0 ; i < n ; i++)
            ans=max(ans, help(maxHeights, i));
        return ans;

        return ans;
    }
};