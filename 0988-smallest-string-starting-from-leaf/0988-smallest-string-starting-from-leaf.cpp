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
    string ans = "~";
private:
    string helper(TreeNode* root, string x) {
        if(!root)
            return ans;
        
        if(!root -> left and !root -> right) {
            ans = min(ans, char(root -> val + 'a') + x);
            return ans;
        }
        
        helper(root -> left, char(root -> val + 'a') + x);
        helper(root -> right, char(root -> val + 'a') + x);
        
        return ans;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");
    }
};