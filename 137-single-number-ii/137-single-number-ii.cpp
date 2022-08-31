class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            umap[nums[idx]]++;
        }
        
        for(auto &ip : umap) {
            if(1 == ip.second)
                return ip.first;
        }
        
        return -1;
    }
};