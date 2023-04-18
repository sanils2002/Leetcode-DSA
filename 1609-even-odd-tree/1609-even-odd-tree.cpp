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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) 
            return true;  // empty tree is Even-Odd
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            int prev_val = (level % 2 == 0) ? 0 : INT_MAX;  // initialize previous value for level
            for(int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                if((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val))
                    || (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val)))
                    return false;  // violates Even-Odd conditions
                prev_val = node->val;
                if(node->left) 
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
            }
            ++level;  // advance to next level
        }
    
        return true;
    }
};