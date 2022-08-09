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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(NULL == p and NULL == q)
            return true;
        if(NULL == p or NULL == q)
            return false;
        
        if(q -> val != p -> val)
            return false;
        
        return isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
};