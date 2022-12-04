class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long total = 0, curr = 0;
        int n = nums.size();
        
        for(int num : nums)
            total += num;
        
        int mn = INT_MAX;
        int index = 0;
        
        for(int idx = 0 ; idx < n ; idx++) {
            curr += nums[idx];
            int avg1 = curr / (idx + 1);
            
            if(n - 1 == idx) {
                if(avg1 < mn)
                    return n - 1;
                else
                    break;
            }
            
            int avg2 = (total - curr) / (n - idx - 1);
            
            if(abs(avg1 - avg2) < mn) {
                mn = abs(avg1 - avg2);
                index = idx;
            }
        }
        
        return index;
    }
};