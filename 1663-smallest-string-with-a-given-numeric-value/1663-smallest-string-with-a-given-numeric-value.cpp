class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a'); // initialize result with n 'a' characters
        k -= n; // subtract n from k, as we have already used n characters
        for(int i = n - 1; i >= 0 && k > 0; i--) {
            int val = min(k, 25); // determine the maximum value we can add to the current character
            result[i] += val; // add the value to the current character
            k -= val; // subtract the added value from k
        }
        
        return result;  
    }
};