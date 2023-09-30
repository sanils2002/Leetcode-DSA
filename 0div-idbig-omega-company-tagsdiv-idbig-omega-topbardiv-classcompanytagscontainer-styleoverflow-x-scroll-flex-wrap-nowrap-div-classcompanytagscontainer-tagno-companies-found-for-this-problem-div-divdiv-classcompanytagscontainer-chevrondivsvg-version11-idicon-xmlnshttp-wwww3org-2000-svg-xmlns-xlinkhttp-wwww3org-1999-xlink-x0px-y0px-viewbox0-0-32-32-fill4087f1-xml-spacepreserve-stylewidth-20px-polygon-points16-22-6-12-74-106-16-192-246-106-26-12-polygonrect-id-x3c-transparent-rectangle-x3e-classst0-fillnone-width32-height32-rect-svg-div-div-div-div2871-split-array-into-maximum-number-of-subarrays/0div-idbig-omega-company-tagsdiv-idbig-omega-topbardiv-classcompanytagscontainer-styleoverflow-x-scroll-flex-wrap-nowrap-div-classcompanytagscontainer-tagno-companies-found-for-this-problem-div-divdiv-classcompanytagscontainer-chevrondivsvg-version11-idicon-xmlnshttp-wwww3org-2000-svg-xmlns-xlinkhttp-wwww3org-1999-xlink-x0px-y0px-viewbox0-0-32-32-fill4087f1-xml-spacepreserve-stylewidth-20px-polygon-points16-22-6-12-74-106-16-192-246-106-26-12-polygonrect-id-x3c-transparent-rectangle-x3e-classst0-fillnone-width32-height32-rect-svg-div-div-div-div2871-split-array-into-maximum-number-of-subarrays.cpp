class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int x = INT_MAX;
        for(auto num : nums)
            x &= num;
        
        if(x)
            return 1;
        
        int y = INT_MAX, val = 0;
        for(auto num : nums) {
            y &= num;
            if(x == y) {
                val++;
                y = INT_MAX;
            }
        }
        
        return val;
    }
};