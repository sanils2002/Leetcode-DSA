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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                int index = left_to_right ? i : size - i - 1;
                level[index] = node->val;
                if(node->left) 
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
            }
        
            res.push_back(level);
            left_to_right = !left_to_right;
        }
    
        return res;
    }
};