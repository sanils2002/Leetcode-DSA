class Solution {
private:
    int helper(int x, int y) {
        if(0 == x or 0 == y)
            return 0;
        if(x >= y)
            return 1 + helper(x - y, y);
        else
            return 1 + helper(x, y - x);
    }
public:
    int countOperations(int num1, int num2) {
        return helper(num1, num2);
    }
};