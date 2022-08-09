class Solution {
protected:
    unordered_set<int> nums;
    unordered_map<int, long long> treePerRoot;
    
    long long countTreewithRoot(int root) {
        if(treePerRoot.count(root))
            return treePerRoot[root];
        long long cnt = 1;
        for(int idx : nums) {
            if(0 == root % idx and nums.count(root / idx))
                cnt += countTreewithRoot(idx) * countTreewithRoot(root / idx);
        }
        return treePerRoot[root] = cnt;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        nums.insert(arr.begin(), arr.end());
        long long ans = 0;
        for(int idx : nums)
            ans += countTreewithRoot(idx);
        return int(ans % 1000000007);
    }
};