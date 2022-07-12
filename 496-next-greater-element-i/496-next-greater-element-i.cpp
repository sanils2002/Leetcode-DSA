class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        unordered_map<int, int> umap;
        stack<int> st;
        
        for(auto idx : nums2) {
            while(!st.empty() and st.top() < idx) {
                umap.insert({st.top(), idx});
                st.pop();
            }
            st.push(idx);
        }
        
        for(int idx = 0 ; idx < n ; idx++) {
            if(umap[nums1[idx]])
                ans[idx] = umap[nums1[idx]];
            else 
                ans[idx] = -1;
        }
        return ans;
    }
};