class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        size_t found = s.find("6");
        
        if(found != string::npos)
            s[found] = '9';
        
        return stoi(s);
    }
};