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
    void inOrderTraversal(TreeNode* node, TreeNode*& newRoot, TreeNode*& currNode) {
        if(node == nullptr)
            return;
            
        inOrderTraversal(node->left, newRoot, currNode);
        if(newRoot == nullptr) {
            newRoot = new TreeNode(node->val);
            currNode = newRoot;
        } 
        else {
            currNode->right = new TreeNode(node->val);
            currNode = currNode->right;
        }
        
        inOrderTraversal(node->right, newRoot, currNode);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
            
        TreeNode* newRoot = nullptr;
        TreeNode* currNode = nullptr;
        inOrderTraversal(root, newRoot, currNode);
        return newRoot;
    }
};