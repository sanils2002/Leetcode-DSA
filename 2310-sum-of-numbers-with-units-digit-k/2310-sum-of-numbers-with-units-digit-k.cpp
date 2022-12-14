class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(0 == num)
            return 0;
        
        for(int i = 1 ; i <= 10 ; i++) {
            if(num % 10 == (i * k) % 10 and i * k <= num)
                return i;
        }
        
        return -1;
    }
};