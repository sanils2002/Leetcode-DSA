class Solution {
public:
    vector<int> countBits(int n) {
        if(0 == n) return {0};
        vector<int>v(n+1, 0);
        v[1] = 1;
        for(int idx = 2 ; idx <= n; ++idx) {
            if(0 == idx % 2) 
                v[idx] = v[idx / 2];
            else 
                v[idx] = v[idx / 2] + 1;
        }
        return v;
    }
};