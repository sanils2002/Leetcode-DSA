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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(NULL == root)
            return false;
        
        if(NULL == root -> left and NULL == root -> right and targetSum == root -> val)
            return true;
        
        bool lhs = hasPathSum(root->left, targetSum - root->val);
        bool rhs = hasPathSum(root->right, targetSum - root->val);
        
        return lhs or rhs;
    }
};