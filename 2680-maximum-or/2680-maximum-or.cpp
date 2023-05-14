class Solution {
private:
    long long helper(vector<long long> &a, int n, int k, int x) {
        vector<long long> pref(n + 1), suff(n + 1);
        long long res, pow = 1;
        
        for(int i = 0 ; i < k ; i++) {
            pow *= x;
        }
        
        pref[0] = 0;
        for(int i = 0 ; i < n ; i++) {
            pref[i + 1] = pref[i] | a[i]; 
        }
        suff[n] = 0;
        for(int i = n - 1 ; i >= 0 ; i--) {
            suff[i] = suff[i + 1] | a[i]; 
        }
        
        res = 0;
        for(int i = 0 ; i < n ; i++) {
            long long x = pref[i] | (a[i] * pow);
            x |= suff[i + 1];
            res = max(res, x);
        }
        
        return res;
        
    }
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<long long> v;
        for(auto num : nums)
            v.push_back(num);
        
        long long orr = helper(v, v.size(), k, 2);
        return orr;
        
    }
};