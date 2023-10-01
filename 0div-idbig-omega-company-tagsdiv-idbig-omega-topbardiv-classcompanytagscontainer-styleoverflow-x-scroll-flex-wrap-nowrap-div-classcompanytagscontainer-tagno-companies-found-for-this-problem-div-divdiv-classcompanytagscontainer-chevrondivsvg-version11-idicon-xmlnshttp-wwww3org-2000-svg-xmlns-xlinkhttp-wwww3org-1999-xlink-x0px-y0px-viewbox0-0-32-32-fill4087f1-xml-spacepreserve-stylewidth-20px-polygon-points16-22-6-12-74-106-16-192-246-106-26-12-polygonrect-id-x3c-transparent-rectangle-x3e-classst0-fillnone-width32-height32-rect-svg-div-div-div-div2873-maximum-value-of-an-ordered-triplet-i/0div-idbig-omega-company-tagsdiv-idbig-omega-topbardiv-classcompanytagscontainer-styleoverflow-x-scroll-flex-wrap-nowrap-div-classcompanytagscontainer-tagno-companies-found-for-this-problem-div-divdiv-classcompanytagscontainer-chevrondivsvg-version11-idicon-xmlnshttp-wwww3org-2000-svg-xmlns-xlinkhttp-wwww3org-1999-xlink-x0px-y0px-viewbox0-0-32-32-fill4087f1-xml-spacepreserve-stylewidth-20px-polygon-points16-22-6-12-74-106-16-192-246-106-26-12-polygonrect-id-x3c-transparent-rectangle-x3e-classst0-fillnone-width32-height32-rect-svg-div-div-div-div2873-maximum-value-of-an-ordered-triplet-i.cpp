class Solution {
typedef long long ll;
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll mx = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                for(int k = j + 1 ; k < nums.size() ; k++) {
                    ll x = (ll)(nums[i] - nums[j]) * nums[k];
                    mx = max(x, mx);
                }
            }
        }
        return mx;
    }
};