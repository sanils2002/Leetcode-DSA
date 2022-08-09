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
private:
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if(NULL == root1 and NULL == root2)
            return true;
        else if(NULL == root1 or NULL == root2)
            return false;
        else if(root1 -> val != root2 -> val)
            return false;
        
        return dfs(root1 -> left, root2 -> right) and dfs(root1 -> right, root2 -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return dfs(root -> left, root -> right);
    }
};