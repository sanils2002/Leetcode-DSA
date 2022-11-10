class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for(auto idx = 0 ; idx < s.size() ; idx++) {
            if(st.size() and s[idx] == st.back())
                st.pop_back();
            else
                st.push_back(s[idx]);
        }
        return st;
    }
};