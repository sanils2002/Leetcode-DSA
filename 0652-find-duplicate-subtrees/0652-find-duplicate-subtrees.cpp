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
    string serialize(TreeNode* root, unordered_map<string, int>& count, vector<TreeNode*>& result) {
        if(!root) {
            return "#";
        }
        string serial = to_string(root->val) + "," + serialize(root->left, count, result) + "," + serialize(root->right, count, result);
        
        if(count[serial]++ == 1) {
            result.push_back(root);
        }
        
        return serial;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> count;
        serialize(root, count, result);
        return result;
    }
};