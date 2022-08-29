class Solution {
public:
    bool isPalindrome(string s) {
        string pal = "";
        for(char &c : s) {
            if(c >= 'A' and c <= 'Z')
                pal.push_back(c + 'a' - 'A');
            else if((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
                pal.push_back(c);
        }
        
        int n = pal.size();
        for(int idx = 0 ; idx < n / 2 ; idx++) {
            if(pal[idx] != pal[n - idx - 1])
                return false;
        }
        
        return true;
    }
};