class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) 
            return 0;

        int maxReach = nums[0];
        int steps = nums[0];
        int jumps = 1;
        for(int i = 1; i < n; i++) {
            if(i == n - 1) 
                return jumps;
            maxReach = max(maxReach, i + nums[i]);
            steps--;
            if(steps == 0) {
                jumps++;
                if(i >= maxReach) 
                    return -1;
                steps = maxReach - i;
            }
        }
   
        return -1;
    }
};