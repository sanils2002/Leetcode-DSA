class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(auto &num : nums) {
            if(num > 0)
                product *= 1;
            else if(num < 0)
                product *= -1;
            else
                return 0;
        }
        
        return product;
    }
};