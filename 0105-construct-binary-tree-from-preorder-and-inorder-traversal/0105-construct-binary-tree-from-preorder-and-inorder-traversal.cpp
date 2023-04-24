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
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorder_map, int pre_start, int in_start, int in_end) {
        if (in_start > in_end) {
            // Base case: no more elements to process
            return nullptr;
        }
        // Create a new node with the value of the first element in the preorder array
        TreeNode* node = new TreeNode(preorder[pre_start]);
        // Find the index of the node's value in the inorder array
        int in_index = inorder_map[node->val];
        // Calculate the number of elements in the left and right subtrees
        int left_size = in_index - in_start;
        int right_size = in_end - in_index;
        // Recursively build the left and right subtrees
        node->left = buildTreeHelper(preorder, inorder_map, pre_start + 1, in_start, in_index - 1);
        node->right = buildTreeHelper(preorder, inorder_map, pre_start + left_size + 1, in_index + 1, in_end);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each element in the inorder array
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        // Call the recursive helper function to build the binary tree
        return buildTreeHelper(preorder, inorder_map, 0, 0, inorder.size() - 1);
    }
};