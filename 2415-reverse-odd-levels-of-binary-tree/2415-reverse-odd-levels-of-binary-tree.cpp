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
    void helper(TreeNode* root1, TreeNode* root2, int k) {
        if(!root1 or !root2)
            return;
        if(0 == k%2)
            swap(root1->val, root2->val);
        helper(root1->left, root2->right, k+1);
        helper(root1->right, root2->left, k+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, 0);
        return root;
    }
};