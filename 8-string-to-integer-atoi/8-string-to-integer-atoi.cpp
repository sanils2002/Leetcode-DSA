class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, index = 0, fin_res = 0;
        
        while(index < s.size() and ' ' == s[index])
            index += 1;
        
        if(index < s.size() and '+' == s[index]) {
            sign = 1;
            index += 1;
        }
        else if(index < s.size() and '-' == s[index]) {
            sign = -1;
            index += 1;
        }
        
        while(index < s.size() and isdigit(s[index])) {
            int digit = s[index] - '0';
            if ((fin_res > INT_MAX / 10) or (fin_res == INT_MAX / 10 and digit > INT_MAX % 10)) {     
                return sign == 1 ? INT_MAX : INT_MIN;
            } 
            fin_res = 10 * fin_res + digit; 
            index += 1;
        }
        
        return sign*fin_res;
    }
};