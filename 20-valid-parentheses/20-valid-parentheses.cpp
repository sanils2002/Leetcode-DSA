class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        
        for(int idx = 1 ; idx < s.size() ; idx++) {
            if(s[idx] == ')' && !st.empty() && st.top() == '(' ) 
                st.pop();
            else if(s[idx] == '}' && !st.empty() && st.top() == '{' ) 
                st.pop();
            else if(s[idx] == ']' && !st.empty() && st.top() == '[' ) 
                st.pop();
            else 
                st.push(s[idx]);
        }
        
        return st.empty();
    }
};