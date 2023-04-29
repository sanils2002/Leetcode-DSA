class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long ans = 1;
        int n = nums.size();
        vector <pair <int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        for(int i = n - 2; i >= 0; i--) {
            ans += (v[i].second > v[i + 1].second) ? n - i : 1;
        }
        
        return ans;
    }
};