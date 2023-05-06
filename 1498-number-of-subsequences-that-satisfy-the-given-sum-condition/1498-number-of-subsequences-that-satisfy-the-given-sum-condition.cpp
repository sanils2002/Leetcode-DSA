class Solution {
const int MOD = 1e9 + 7;
private:
    int power(long long a, long long b) {
        int res = 1;
        while(b) {
            if(b & 1) 
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
    
        return res;
}
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        
        int l = 0, r = n - 1;
        while(l <= r) {
            if(nums[l] + nums[r] > target) {
                r--;
            } 
            else {
                ans = (ans + power(2, r - l)) % MOD;
                l++;
            }
        }
    
        return ans;
    }
};