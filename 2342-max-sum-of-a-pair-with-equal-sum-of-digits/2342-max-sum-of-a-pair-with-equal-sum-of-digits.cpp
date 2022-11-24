class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1, v[82] = {}; //9*9
        for(auto &num : nums) {
            int idx = 0;
            for(auto i = num ; i ; i /= 10)
                idx += (i % 10);
            if(v[idx])
                res = max(res, v[idx] + num);
            v[idx] = max(v[idx], num);
        }
        return res;
        
    }
};