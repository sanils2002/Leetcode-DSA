class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int val = -1;
        vector<int> v(10001, 0);
        
        for(auto &num : nums) {
            if(0 != v[abs(num)] and 0 == v[abs(num)] + num)
                val = max(val, abs(num));
            else
                v[abs(num)] = num;
        }
        return val;
    }
};