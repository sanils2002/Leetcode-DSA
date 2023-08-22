class Solution {
public:
    string convertToTitle(int columnNumber) {
        string sanils2002;
        while(columnNumber--) {
            sanils2002 = char('A' + columnNumber%26) + sanils2002;
            columnNumber /= 26;
        }
        return sanils2002;
    }
};