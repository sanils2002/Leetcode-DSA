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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) {
            return NULL;
        }
        
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode* root = new TreeNode(nums[max_idx]);
        
        vector<int> left_nums(nums.begin(), nums.begin() + max_idx);
        vector<int> right_nums(nums.begin() + max_idx + 1, nums.end());
        
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);
        
        return root;
    }
};