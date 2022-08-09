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
    void inOrderTraversal(TreeNode* root, vector<int> &res) {
        if(NULL == root)
            return;
        inOrderTraversal(root->left, res);
        res.push_back(root -> val);
        inOrderTraversal(root -> right, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inOrderTraversal(root, res);
        return res[k-1];
    }
};