class Solution {
private:
    bool isSymmetric(int num) {
        string numStr = to_string(num);
        int n = numStr.length();
        
        if(n % 2 != 0) {
            // Numbers with odd number of digits are never symmetric
            return false;
        }
        
        int leftSum = 0;
        int rightSum = 0;
        
        for(int i = 0; i < n / 2; ++i) {
            leftSum += numStr[i] - '0';  // Convert char to int
            rightSum += numStr[n - 1 - i] - '0';  // Convert char to int
        }
        
        return leftSum == rightSum;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num = low; num <= high; ++num) {
            if(isSymmetric(num)) {
                count++;
            }
        }
        return count;
    }
};