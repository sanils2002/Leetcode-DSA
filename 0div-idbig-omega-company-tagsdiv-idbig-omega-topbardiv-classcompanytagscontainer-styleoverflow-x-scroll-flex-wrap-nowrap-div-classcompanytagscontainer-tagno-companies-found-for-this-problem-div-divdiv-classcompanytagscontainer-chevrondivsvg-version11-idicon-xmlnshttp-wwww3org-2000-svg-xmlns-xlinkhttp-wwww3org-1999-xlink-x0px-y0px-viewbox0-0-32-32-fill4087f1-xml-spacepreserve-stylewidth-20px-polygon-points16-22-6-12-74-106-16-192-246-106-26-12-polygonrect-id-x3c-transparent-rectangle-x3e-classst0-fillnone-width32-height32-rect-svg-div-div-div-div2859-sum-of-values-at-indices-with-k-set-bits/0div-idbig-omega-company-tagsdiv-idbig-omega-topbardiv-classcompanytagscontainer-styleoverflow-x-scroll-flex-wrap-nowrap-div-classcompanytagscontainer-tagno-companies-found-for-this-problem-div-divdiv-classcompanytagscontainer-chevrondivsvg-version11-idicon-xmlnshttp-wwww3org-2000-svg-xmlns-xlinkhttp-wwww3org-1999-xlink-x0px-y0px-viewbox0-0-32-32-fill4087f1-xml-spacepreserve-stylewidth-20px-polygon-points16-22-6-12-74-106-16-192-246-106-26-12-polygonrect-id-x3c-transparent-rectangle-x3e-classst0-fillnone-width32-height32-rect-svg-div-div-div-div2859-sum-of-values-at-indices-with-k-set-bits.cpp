class Solution {
private:
    int check(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(check(i) == k)
                sum += nums[i];
        }
        return sum;
    }
};