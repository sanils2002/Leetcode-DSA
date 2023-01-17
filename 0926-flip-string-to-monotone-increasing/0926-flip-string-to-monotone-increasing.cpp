class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, on_e = 0;
        for(auto &x : s) {
            if('0' == x)
                res = min(on_e, res + 1);
            else 
                on_e++;
        }
        
        return res;
    }
};