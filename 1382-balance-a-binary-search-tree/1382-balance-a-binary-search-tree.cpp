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
    void inorder(TreeNode* root, vector<int>& values) {
        if(!root) 
            return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
    
    TreeNode* buildTree(vector<int>& values, int left, int right) {
        if(left > right) 
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = buildTree(values, left, mid - 1);
        root->right = buildTree(values, mid + 1, right);
        return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        return buildTree(values, 0, values.size() - 1);
    }
};