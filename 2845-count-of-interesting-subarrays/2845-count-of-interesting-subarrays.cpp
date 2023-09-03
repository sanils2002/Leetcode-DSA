class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        map<int, int> mp;
        long long res = 0, cnt = 0;
        
        mp[0] = 1;
        for(int num : nums) {
            cnt += (num % modulo == k);
            res += mp[(cnt - k + modulo) % modulo];
            mp[cnt % modulo]++;
        }
        
        return res;
    }
};