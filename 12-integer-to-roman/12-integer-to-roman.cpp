class Solution {
public:
    string intToRoman(int num) {
        vector<int> number {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int x = 12;
        
        string sanils2002 ="";
        while(num > 0) {
            int temp = num / number[x];
            num %= number[x];
            while(temp) {
                sanils2002 += roman[x];
                temp -= 1;
            }
            x -= 1;
        }
        
        return sanils2002;
    }
};