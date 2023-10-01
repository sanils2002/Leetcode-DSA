class Solution {
typedef long long ll;
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll mx = 0;
        vector<long long> pref(n, 0), suff(n, 0);
        pref[0] = nums[0], suff[n - 1] = nums[n - 1];
        
        for(int i = 1 ; i < n ; i++)
            pref[i] = max(pref[i - 1], (ll)nums[i]);
        
         for(int i = n - 2 ; i >= 0 ; i--)
            suff[i] = max(suff[i + 1], (ll)nums[i]);
        
        for(int i = 1 ; i < n - 1 ; i++) {
            ll l = pref[i - 1], r = suff[i + 1];
            mx = max(mx, ((ll) l - (ll)nums[i]) * (ll) r);
        }
        
        return mx;
    }
};