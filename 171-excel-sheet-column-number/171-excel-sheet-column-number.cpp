class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sanils2002 = 0;
        for(char title : columnTitle) {
            int x = title - 'A' + 1;
            sanils2002 *= 26;
            sanils2002 += x;
        }
        return sanils2002;
    }
};