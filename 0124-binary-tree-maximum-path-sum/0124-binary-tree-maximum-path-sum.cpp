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
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if (!root) 
            return 0;
        
        int left = maxPathSumHelper(root->left, maxSum);
        int right = maxPathSumHelper(root->right, maxSum);
        
        int rootMax = max(root->val, max(root->val + left, root->val + right));
        int rootSubtreeMax = max(rootMax, root->val + left + right);
        
        maxSum = max(maxSum, rootSubtreeMax);
        
        return rootMax;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};