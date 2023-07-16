class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), j = 0, mx=0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++){
            while(j < i && nums[j] + k < nums[i] - k){
                  j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};