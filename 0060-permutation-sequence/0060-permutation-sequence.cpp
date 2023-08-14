class Solution {
public:
    string getPermutation(int n, int k) {
        // Create a vector to store the numbers [1, 2, ..., n]
        vector<int> nums;
        for(int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
    
        // Create a vector to store factorials
        vector<int> factorial(n + 1, 1);
        for(int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
    
        // Adjust k to be 0-based index
        --k;
    
        // Build the result string
        string result = "";
        for(int i = n; i > 0; --i) {
            int index = k / factorial[i - 1];
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial[i - 1];
        }
    
        return result;
    }
};