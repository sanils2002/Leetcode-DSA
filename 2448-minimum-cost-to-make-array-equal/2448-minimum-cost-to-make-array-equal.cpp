class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        #define ll long long
        map<ll,ll> mp;
        ll x = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++)
                mp[nums[idx]] += cost[idx], x += cost[idx];
        ll rem = x/2;
        ll res = 0, e = -1;
        for(auto &[k,v] : mp){
            ll r = min(v, rem);
            rem -= r;
            if(!rem){
                e = k;
                break;
            }
        }
        for(auto &[k,v]:mp)
            res += abs(k-e)*v;
        return res;
    }
};