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
    bool findTargetHelper(TreeNode* root, int k, unordered_set<int>& set) {
        if(!root) 
            return false;
        if(set.count(k - root->val)) 
            return true;
        set.insert(root->val);
        return findTargetHelper(root->left, k, set) || findTargetHelper(root->right, k, set);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return findTargetHelper(root, k, set);
    }
};