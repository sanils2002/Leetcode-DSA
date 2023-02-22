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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode *node = root;
        stack<TreeNode*> stack;

        while(!stack.empty() || node != nullptr) {
            /* push all nodes up to (and including) this subtree's maximum on
             * the stack. */
            while(node != nullptr) {
                stack.push(node);
                node = node->right;
            }

            node = stack.top();
            stack.pop();
            sum += node->val;
            node->val = sum;

            /* all nodes with values between the current and its parent lie in
             * the left subtree. */
            node = node->left;
        }

        return root;
    }
};