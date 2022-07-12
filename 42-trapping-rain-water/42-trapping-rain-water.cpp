class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(0 == n)
            return 0;
        vector<int> prefix(n), suffix(n);
        
        int equilibrium = 0;
        
        prefix[0] = height[0];
        for(int idx = 1 ; idx < n ; idx++) {
            prefix[idx] = max(prefix[idx-1], height[idx]);
        }
        
        suffix[n-1] = height[n-1];
        for(int idx = n - 2 ; idx >= 0 ; idx--) {
            suffix[idx] = max(suffix[idx+1], height[idx]);
        }
        
        for(int idx = 0 ; idx < n ; idx++) {
            equilibrium += min(prefix[idx], suffix[idx]) - height[idx];
        }
        
        return equilibrium;
    }
};