class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) {
            return false;
        }
        
        unordered_map<int, int> modMap{{0, -1}};
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            if(k != 0) {
                sum %= k;
            }
            if(modMap.count(sum)) {
                if(i - modMap[sum] > 1) {
                    return true;
                }
            } 
            else {
                modMap[sum] = i;
            }
        }
        
        return false;
    }
};