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
    int solver(TreeNode* root, int MaxVal, int MinVal) {
        if(NULL == root) {
            return abs(MaxVal - MinVal);
        }
        
        MaxVal = max(root -> val, MaxVal);
        MinVal = min(root -> val, MinVal);

        int left = solver(root -> left, MaxVal, MinVal);
        int right = solver(root -> right, MaxVal, MinVal);

        return max(right, left);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(NULL == root) 
            return 0;
        return solver(root, root -> val, root -> val);
    }
};