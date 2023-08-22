class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        int maxFreq = 0;
        
        int i = 0;
        int ans = 0;
        for(int j = 0 ; j < n ; j++) {
            mp[nums[j]]++;
            maxFreq = max(maxFreq, mp[nums[j]]);
            if(j - i + 1 - maxFreq > k){
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, maxFreq);
        }
    
        return ans;
    }
};