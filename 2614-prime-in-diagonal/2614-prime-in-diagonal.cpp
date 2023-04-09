class Solution {
private:
    bool isprime(int n) {
        if(n == 0 || n == 1)
            return false;
        for(int i = 2 ; i * i <= n ; i++) { 
            if(n % i == 0)
                return false;
        }
        
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int lar = 0;
        int n = nums.size();
        for(int i = 0 ; i  < n ; i++) {
            if(isprime(nums[i][i]))
                lar = max(lar, nums[i][i]);
            if(isprime(nums[i][n-i-1]))
                lar = max(lar, nums[i][n-i-1]);
        }
        
        return lar;
    }
};