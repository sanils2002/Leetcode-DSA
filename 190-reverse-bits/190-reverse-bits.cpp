class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp = n, val = 0, bit_val = 31;
        while(temp > 0) {
            int mem_all = temp % 2;
            val += (pow(2, bit_val) * mem_all);
            bit_val--;
            temp /= 2;
        }
        return val;
    }
};