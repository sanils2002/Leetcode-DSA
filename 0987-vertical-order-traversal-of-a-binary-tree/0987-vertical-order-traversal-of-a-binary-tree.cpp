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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        
        map<int, vector<int>> nodes;
        queue<pair<TreeNode*, int>> q; // pair of (node, column)
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            map<int, vector<int>> columnNodes;
            for(int i = 0; i < size; i++) {
                auto [node, col] = q.front();
                q.pop();
                columnNodes[col].push_back(node->val);
                if(node->left) {
                    q.push({node->left, col - 1});
                }
                if(node->right) {
                    q.push({node->right, col + 1});
                }
            }
            
            for(auto& p : columnNodes) {
                auto& column = p.second;
                sort(column.begin(), column.end());
                nodes[p.first].insert(nodes[p.first].end(), column.begin(), column.end());
            }
        }
        
        for (auto& p : nodes) {
            result.push_back(p.second);
        }
    
        return result;
    }
};