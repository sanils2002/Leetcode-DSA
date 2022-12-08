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
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) 
            return;
        if(NULL == root -> left && NULL == root -> right)
            v.push_back(root->val);
        
        inorder(root -> left, v);
        inorder(root -> right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        inorder(root1, first);
        inorder(root2, second);
        
        if(first.size() != second.size())
            return false;
        
        for(int idx = 0 ; idx < first.size() ; idx++) {
            if(first[idx] != second[idx])
                return false;
        }
        
        return true;
    }
};