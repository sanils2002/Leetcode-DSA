class Solution {
public:
    bool detectCapitalUse(string w) {
        int up = 0, low = 0;
        for(char c : w) {
            if(isupper(c)) {
                up++;
            } 
            else {
                low++;
            }
        }
        return up == w.size() || low == w.size() || (up == 1 && isupper(w[0]));
    }
};