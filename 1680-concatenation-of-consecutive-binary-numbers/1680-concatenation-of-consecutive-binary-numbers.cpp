class Solution {
private:
    int numberOfBits(int n) {
		  return log2(n) + 1;
    }
public:
    int concatenatedBinary(int n) {
        long val = 0, MOD = 1e9 + 7;
        for(int idx = 1 ; idx <= n ; idx++) {
            int len = numberOfBits(idx);
            val = ((val << len) % MOD + idx) % MOD;
        }
        return val;
    }
};