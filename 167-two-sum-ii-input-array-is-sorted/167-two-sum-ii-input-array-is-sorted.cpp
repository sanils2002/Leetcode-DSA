class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(umap.count(target - nums[idx]) > 0)
                return {umap[target - nums[idx]]+1, idx+1};
            umap[nums[idx]] = idx;
        }
        return {};
    }
};