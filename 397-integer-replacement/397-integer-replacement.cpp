class Solution {
private:
    long long helper(long long n){
        if(1 == n) {
            return 0;
        }
        if(0 == n % 2){
            return 1 + helper(n / 2);
        }
        else{
           long long op1 = helper(n - 1);
           long long op2 = helper(n + 1);
           return 1 + min(op1, op2);
        }
    }
public:
    int integerReplacement(int n) {
        return helper(n);
    }
};