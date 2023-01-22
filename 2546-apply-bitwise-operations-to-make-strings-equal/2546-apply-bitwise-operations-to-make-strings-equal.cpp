class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s == target)
            return true;
        int one_s = 0, zero_s = 0;
        int one_x = 0, zero_x = 0;
        for(auto &x : s) {
            if(x == '1')
                one_s++;
            else
                zero_s++;
        }
        for(auto &r : target) {
            if(r == '1')
                one_x++;
            else
                zero_x++;
        }
        
        cout << one_s << " " << zero_s << " " << one_x << " " << zero_x << "\n";
        if(one_s >= 1 and one_x == 0)
            return false;
        if(one_s == 0 and one_x >= 1)
            return false;
        return true;
        
        
    }
};