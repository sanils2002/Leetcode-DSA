class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int x = 0, mx = 0;
        for(auto &num : nums) {
            if(num == 0)
                x = 0;
            else
                x++, mx = max(mx, x);
        }
        
        return mx;
    }
};