class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> pref(n + 1, 0);
        long long val = 0;
        
        for(int i = 0 ; i < n ; i++){
            val -= pref[i];
            nums[i] -= val;
            
            if(nums[i] < 0) 
                return false;
            if(i + k <= n){   
                val += nums[i];
                pref[i + k] += nums[i];
                nums[i] = 0;
            }
            else if(nums[i] > 0)
                return false;
        }
        return true;
    }
};