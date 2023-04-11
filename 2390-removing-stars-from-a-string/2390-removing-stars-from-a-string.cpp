class Solution {
public:
    string removeStars(string s) {
        string star;
        for(int idx = 0 ; idx < s.size() ; idx++) {
            if('*' == s[idx]) {
                if(!star.empty())
                    star.pop_back();
            }
            else
                star += s[idx];
        }
        return star;
    }
};