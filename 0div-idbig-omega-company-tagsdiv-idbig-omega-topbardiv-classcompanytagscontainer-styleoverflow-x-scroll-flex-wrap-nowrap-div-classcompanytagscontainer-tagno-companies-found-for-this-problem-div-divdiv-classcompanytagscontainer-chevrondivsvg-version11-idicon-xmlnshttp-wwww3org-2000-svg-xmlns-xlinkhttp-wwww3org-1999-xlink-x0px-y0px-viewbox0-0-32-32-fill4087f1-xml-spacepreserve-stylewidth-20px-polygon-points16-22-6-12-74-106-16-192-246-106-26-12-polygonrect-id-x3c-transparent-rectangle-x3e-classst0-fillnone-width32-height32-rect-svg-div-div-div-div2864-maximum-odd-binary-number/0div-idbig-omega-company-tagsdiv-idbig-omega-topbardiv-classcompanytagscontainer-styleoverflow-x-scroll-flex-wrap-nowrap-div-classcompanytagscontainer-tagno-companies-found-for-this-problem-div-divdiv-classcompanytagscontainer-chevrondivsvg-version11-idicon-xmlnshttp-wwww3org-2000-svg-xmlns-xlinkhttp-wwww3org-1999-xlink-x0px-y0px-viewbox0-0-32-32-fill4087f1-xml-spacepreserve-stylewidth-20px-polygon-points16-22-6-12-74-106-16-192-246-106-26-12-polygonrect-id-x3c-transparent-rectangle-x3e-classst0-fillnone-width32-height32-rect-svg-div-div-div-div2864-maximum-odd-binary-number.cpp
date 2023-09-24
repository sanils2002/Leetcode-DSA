class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onesCount = 0;
        int zerosCount = 0;

        for(char c : s) {
            if(c == '1') {
                onesCount++;
            } 
            else if (c == '0') {
                zerosCount++;
            }
        }

        string result = string(onesCount - 1, '1') + string(zerosCount, '0') + '1';

        return result;
    }
};