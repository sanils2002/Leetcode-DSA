class Solution {
public:
    bool isFascinating(int n) {
        map<char, int> mp;
        string s = "";
        
        s += (to_string(n) + to_string(2*n) + to_string(3*n));
        for(auto &x : s)
            mp[x]++;
        
        for(auto &ip : mp) {
            if(ip.second > 1 or ip.first == '0')
                return false;
        }
        
        return true;
        
        cout << s;
        
        
    }
};