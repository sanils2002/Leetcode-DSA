class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st; //Stack
        int l = nums.size(), r = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            while(!st.empty() and nums[st.top()] > nums[i]) {
                int x = st.top(); st.pop(); l = min(l, x);
            }
                
            st.push(i);
        }
        st = stack<int>();
        for(int i = nums.size() - 1 ; i >= 0 ; i--) {
            while(!st.empty() and nums[st.top()] < nums[i]) {
                int x = st.top(); st.pop(); r = max(r, x);
            }
                
            st.push(i);
        }
        
        return r - l > 0 ? r - l + 1 : 0;
    }
};