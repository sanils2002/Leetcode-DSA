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
    int sum = 0;
private:
    int helper(TreeNode* root, string x) {
        if(!root)
            return sum;
        
        if(!root -> left and !root -> right) {
            sum += stoi(x + to_string(root -> val));
            return sum;
        }
        
        helper(root -> left, x + to_string(root -> val));
        helper(root -> right, x + to_string(root -> val));
        
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, "");
    }
};