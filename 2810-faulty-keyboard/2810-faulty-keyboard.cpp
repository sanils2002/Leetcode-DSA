class Solution {
public:
    string finalString(string s) {
        string r = "";
        for(char x : s) {
            if(x != 'i') {
                r += x;
            }
            else {
                reverse(r.begin(), r.end());
            }
        }
        return r;
    }
};