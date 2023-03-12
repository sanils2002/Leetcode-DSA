class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long cnt = 0, xorSum = 0;
        unordered_map<int, int> umap;
        umap[xorSum]++;
        for(auto &num : nums) {
            xorSum ^= num;
            cnt += umap[xorSum];
            umap[xorSum]++;
        }
        
        return cnt;
    }
};