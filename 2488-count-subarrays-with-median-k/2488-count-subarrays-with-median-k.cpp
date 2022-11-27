class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        
        bool flag = false;
        int sum = 0;
        long long ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < k)
                sum -= 1;
            else if(nums[i] > k)
                sum += 1;
            
            if(k == nums[i])
                flag = true;
            
            if(flag)
                ans += mp[sum] + mp[sum-1];
            else
                mp[sum]++;
        }
        
        return ans;
    }
};