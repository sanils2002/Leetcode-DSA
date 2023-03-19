class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) {
            if(nums[ans] < num) {
                ans++;
            }
        }
        
        return ans;
    }
};