class Solution {
public:
    string toHex(int num) {
        if(0 == num)
            return "0";
        
        unsigned int n = num;
        string hex = "";
        string keys = "0123456789abcdef";
        
        while(n > 0) {
            hex.push_back(keys[n%16]);
            n -= (n%16);
            n /= 16;
        }
        
        reverse(hex.begin(), hex.end());
        return hex;
    }
};