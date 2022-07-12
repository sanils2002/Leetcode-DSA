class Solution {
public:
    int countAsterisks(string s) {
        bool asTerisks = false;
        int sanils2002 = 0;
        for(int idx = 0 ; idx < s.length() ; idx++) {
            if(false == asTerisks and '*' == s[idx])
                sanils2002 += 1;
            else if('|' == s[idx])
                asTerisks = !asTerisks;
        }
        return sanils2002;
    }
};