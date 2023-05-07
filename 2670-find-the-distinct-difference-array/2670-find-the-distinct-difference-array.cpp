class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> DIFF(n);
        unordered_set<int> pref, suff;
        for(int i = 0 ; i < n ; i++) {
            pref.insert(nums[i]);
            for(int j = n - 1 ; j > i ; j--) {
                suff.insert(nums[j]);
            }
            DIFF[i] = pref.size() - suff.size();
            suff.clear();
        }
            
        return DIFF;
    }
};