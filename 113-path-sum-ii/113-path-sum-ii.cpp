/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> path;
        
        stack<TreeNode*> st;
        st.push(nullptr);
        st.push(root);
        
        while(!empty(st)) {
            TreeNode* node = st.top();
            st.pop();
            if(!node) {
                targetSum += path.back();
                path.pop_back();
            }
            else {
                path.push_back(node -> val);
                targetSum -= node -> val;
                if(!node -> left and !node -> right and !targetSum) {
                    ans.push_back(path);
                }
                if(node -> left) {
                    st.push(nullptr);
                    st.push(node -> left);
                }
                if(node -> right) {
                    st.push(nullptr);
                    st.push(node -> right);
                }
            }
        }
        
        return ans;
    }
};