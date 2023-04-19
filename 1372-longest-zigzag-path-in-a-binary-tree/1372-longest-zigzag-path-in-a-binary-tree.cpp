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
    void traverse(TreeNode* node, bool isLeft, int len, int& maxLen) {
        if(!node) {
            maxLen = max(maxLen, len - 1);
            return;
        }
        if(isLeft) {
            traverse(node->left, false, len + 1, maxLen);
            traverse(node->right, true, 1, maxLen);
        } 
        else {
            traverse(node->right, true, len + 1, maxLen);
            traverse(node->left, false, 1, maxLen);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int maxLen = 0;
        traverse(root, true, 0, maxLen);
        traverse(root, false, 0, maxLen);
        return maxLen;
    }
};