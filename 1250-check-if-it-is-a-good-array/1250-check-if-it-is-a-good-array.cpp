class Solution {
private:
    int gcd(int x, int y) {
        while(x%y) {
            int rem = x % y;
            x = y;
            y = rem;
        }
        return y;
    }
public:
    bool isGoodArray(vector<int>& nums) {
        int temp = 0;
        for(int idx = 0 ; idx < nums.size() ; idx++) {
            temp = gcd(temp, nums[idx]);
            if(1 == temp)
                return true;
        }
        return false;
    }
};