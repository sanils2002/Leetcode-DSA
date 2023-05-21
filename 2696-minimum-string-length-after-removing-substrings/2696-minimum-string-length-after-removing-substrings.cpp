class Solution {
public:
    int minLength(string s) {
        bool changed = true;
        while(changed) {
            changed = false;
            size_t pos = s.find("AB");
            if(pos != string::npos) {
                s.erase(pos, 2);
                changed = true;
            }
        
            pos = s.find("CD");
            if(pos != string::npos) {
                s.erase(pos, 2);
                changed = true;
            }
        }
    
        return s.length();
    }
};