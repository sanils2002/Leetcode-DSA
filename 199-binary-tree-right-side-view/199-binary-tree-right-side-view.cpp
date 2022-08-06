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
    void process(TreeNode* root, vector<int> &res, int idx){
        if(NULL == root) 
            return;
        
        if(idx == res.size())
            res.push_back(root -> val);
        
		// Right first DFS
        process(root -> right, res, idx + 1);
        process(root -> left, res, idx + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        process(root, res, 0);
        return res;
    }
};