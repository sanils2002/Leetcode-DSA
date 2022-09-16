class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            if(umap.find(nums[idx]) != umap.end())
                if(abs(umap[nums[idx]] - idx) <= k)
                    return true;
            umap[nums[idx]] = idx;
        }
        
        return false;
    }
};