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
protected: 
    int value(TreeNode* root, int &diameter) {
        if(!root) return 0;
        
        int l = value(root -> left, diameter);
        int r = value(root -> right, diameter);
        diameter = max(diameter, l+r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        value(root, diameter);
        return diameter;
    }
};