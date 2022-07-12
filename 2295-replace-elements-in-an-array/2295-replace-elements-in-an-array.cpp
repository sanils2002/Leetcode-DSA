class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> umap;
        
        for(int idx = 0 ; idx < nums.size() ; idx++)
            umap[nums[idx]] = idx;
        
        for(auto ip:operations) {
            int x1 = ip[0];
            int x2 = ip[1];
            int index = umap[x1];
            nums[index] = x2;
            umap[x2] = index;
        }
        
        return nums;
    }
};