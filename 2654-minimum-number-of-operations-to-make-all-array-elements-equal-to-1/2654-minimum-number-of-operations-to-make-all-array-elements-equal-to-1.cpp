class Solution {
private:
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1) {
                cnt++;
            }
        }

        if(cnt > 0) {
            return n - cnt;
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            int num = nums[i];
            for(int j = i + 1; j < n ; j++) {
                num = gcd(num, nums[j]);
                if(num == 1) {
                    ans = min(ans, j - i);
                    break;
                }
            }
            if(num != 1) {
                break;
            }
        }
        if(ans == INT_MAX) {
            return -1;
        }
        
        return n - 1 + ans;
    }
};