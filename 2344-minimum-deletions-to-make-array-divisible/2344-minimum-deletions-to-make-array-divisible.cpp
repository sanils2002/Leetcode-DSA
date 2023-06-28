class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc = 0;
        for (int i : numsDivide) {
            gc = __gcd(gc, i);
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (gc % nums[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};