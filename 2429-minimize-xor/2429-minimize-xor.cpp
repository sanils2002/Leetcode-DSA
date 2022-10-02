class Solution {
private:
    int helper(int num2) {
        int cnt = 0;
        while(0 !=num2) {
            if(1 == (num2 & 1)) {
                cnt++;
            }
            num2 = num2 >> 1;
        }
        return cnt;
    }
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int y = helper(num2);
        
        int tmp = y;
        int val = 0;
        
        for(int idx = 31 ; idx >= 0 and tmp > 0; idx--) {
            if((x & (1 << idx)) > 0) {
                val |= (1 << idx);
                tmp -= 1;
            }
        }
        for(int idx = 0 ; idx <=31 and tmp > 0; idx++) {
            if(0 == (x & (1 << idx))) {
                val |= (1 << idx);
                tmp -= 1;
            }
        }
        return val;
    }
};