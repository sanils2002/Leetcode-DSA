class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        
        int op = 0;
        set<int> s;
        
        bool flag = false;
        for(auto val : nums) {
            if(val <= k)
                s.insert(val);
            op++;
            if(s.size() == k) {
                return op;
            }
        }
        
        return -1;
    }
};