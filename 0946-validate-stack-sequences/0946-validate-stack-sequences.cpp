class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int idx = 0;
        for(auto f : pushed) {
            st.push(f);
            while(!st.empty() and idx < pushed.size() and popped[idx] == st.top()) {
                st.pop();
                idx++;
            }
        }
        
        return idx == pushed.size();
    }
};