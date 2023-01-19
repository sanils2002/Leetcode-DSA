class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mod_count;
        mod_count[0] = 1; // initialize count of 0 to 1
        int count = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            if(sum < 0) {
                sum += k;
            }
            if(mod_count.find(sum) != mod_count.end()) {
                count += mod_count[sum];
            }
            mod_count[sum]++;
        }
    
        return count;
    }
};