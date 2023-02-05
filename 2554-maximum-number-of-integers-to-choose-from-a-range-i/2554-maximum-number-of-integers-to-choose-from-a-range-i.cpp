class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        vector<int> v(100000);
        for(int i = 0 ; i < banned.size() ; i++) {
            v[banned[i]] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            if(!v[i] && maxSum - i >= 0) {
                ans++;
                maxSum -= i;
                }
        }
        
        return ans;
    }
};