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
    int excessCoins(TreeNode* node) {
        if(!node) 
            return 0;
        int left = excessCoins(node->left);
        int right = excessCoins(node->right);
        return node->val + left + right - 1; // compute excess coins
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop();
            if(!node) 
                continue;
            int left = excessCoins(node->left);
            int right = excessCoins(node->right);
            moves += abs(left) + abs(right); // accumulate moves needed for subtree
            if(node->left) 
                q.push(node->left);
            if(node->right) 
                q.push(node->right);
            node->val += left + right; // distribute excess coins to parent
        }
        return moves;
    }
};