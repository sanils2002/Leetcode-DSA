class Solution {
private:
    int idx = 0;
public:
    int calculate(string s) {
        vector<int> calc;
        char sign = '+';
        
        int num = 0;
        while(idx < s.size()) {
            char ch = s[idx++];
            if(isdigit(ch)) {
                num *= 10;
                num += ch - '0';
            }
            if('(' == ch)
                num = calculate(s);
            if(idx >= s.size() || '+' == ch || '-' == ch || ')' == ch) {
                if('+' == sign)
                    calc.push_back(num);
                else
                    calc.push_back(-num);
                sign = ch;
                num = 0;
            }
            if(')' == ch)  
                break;
        }
        
        return accumulate(calc.begin(), calc.end(), 0);
    }
};