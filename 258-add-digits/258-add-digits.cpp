class Solution {
public:
    int addDigits(int num) {
        int sum_one = 0;
        while(num) {
            sum_one += (num%10);
            num /= 10;
        }
        
        if(sum_one < 10)
            return sum_one;
        else
            return addDigits(sum_one);
    }
};