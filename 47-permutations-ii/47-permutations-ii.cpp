class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perm2;
        do {
            perm2.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        
        return perm2;
    }
};