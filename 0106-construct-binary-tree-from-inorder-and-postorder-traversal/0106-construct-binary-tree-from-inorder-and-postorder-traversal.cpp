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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& map) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        // Create a new TreeNode with the value at the end of the postorder array.
        TreeNode* root = new TreeNode(postorder[postEnd]);
        // Get the index of the root value in the inorder array.
        int rootIndex = map[root->val];
        // Recursively build the left and right subtrees.
        root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + rootIndex - inStart - 1, map);
        root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + rootIndex - inStart, postEnd - 1, map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a hashmap to store the indices of the inorder array.
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        // Call the recursive helper function to construct the binary tree.
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, map);
    }
};